/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "../../Maximilian/maximilian.h"
#include "filter.hpp"
#include "Oscillator.hpp"


//==================================================================================
/**
  This is for describing a sound. Very simple and you don't really need to worry
  about this.
 */
struct SimpleSound : public SynthesiserSound
{
    bool appliesToNote(int) override { return true; }
    bool appliesToChannel(int) override { return true; }
};

//==================================================================================
/**
  This is for each voicing in a polyphonic synthesier. It should contain the DSP
  code necessary to generate a sound.
 
 prepareToPlay();
 double currentFrame = 0;
 
 auto writePointer = outBlock.getBuffer().data();
 for (int i = 0; i < outBlock.getBuffer().size(); ++i)
 {
 currentFrame =;
 writePointer[i] = adsrEnv.adsr(currentFrame, adsrEnv.trigger);
 graphic.addSample(writePointer[i]);
 */
class SimpleVoice : public SynthesiserVoice
{
public:
    SimpleVoice() : level(0), oscMix(0.5), oscAfreq(0), oscBfreq(0), oscAtune(0), oscBtune(0), currentFrame(0), oscEnvAttack(1000), oscEnvDecay(100), oscEnvSustain(1), oscEnvRelease(2000), filterCutOffFreq(100), filterResonance(10), oscAoct(0), oscBoct(0), oscAWaveform (0), oscBWaveform(0)
    {
        std::cout << "Instanciated SimpleVoice" << std::endl;
    }
    
    void setParameters (double oscAttack, double oscDecay, double oscRelease, double oscSustain, double filterCut, double filterRes, int waveFormA, int waveFormB, int oscAOctave, int oscBOctave, double oscMx)
    
    {
        oscEnvAttack = oscAttack;
        oscEnvDecay = oscDecay;
        oscEnvRelease = oscRelease;
        oscEnvSustain = oscSustain;
        oscMix = oscMx;
        
        oscAoct = oscAOctave;
        oscBoct = oscBOctave;
        
        filterCutOffFreq = filterCut;
        filterResonance = filterRes;
        oscAWaveform = waveFormA;
        oscBWaveform = waveFormB;
        oscA.setOscillator(oscAWaveform);
        oscB.setOscillator(oscBWaveform);
        
    }

    bool canPlaySound (SynthesiserSound* sound) override
    {
        return dynamic_cast<SimpleSound*> (sound) != nullptr;
    }

    void startNote (int midiNoteNumber,
                    float velocity,
                    SynthesiserSound*,
                    int) override
    {
        level = velocity;
        
        oscAfreq = MidiMessage::getMidiNoteInHertz(midiNoteNumber + oscAoct);
        oscBfreq = MidiMessage::getMidiNoteInHertz(midiNoteNumber + oscBoct);
        
        oscAfreq += (MidiMessage::getMidiNoteInHertz(midiNoteNumber + oscAoct + 1) - MidiMessage::getMidiNoteInHertz(midiNoteNumber + oscAoct)) * oscAtune;
        oscBfreq += (MidiMessage::getMidiNoteInHertz(midiNoteNumber + oscBoct + 1) - MidiMessage::getMidiNoteInHertz(midiNoteNumber + oscBoct)) * oscBtune;
        
    
    }

    void stopNote (float, bool) override
    {
        level = 0;
        clearCurrentNote();
    }

    void renderNextBlock (AudioSampleBuffer& outputBuffer,
                          int                startSample,
                          int                numberSamples) override
    {
        while (--numberSamples >= 0)
        {

            double currentFrame = 0;
            
            oscEnv.setAttack(oscEnvAttack);
            oscEnv.setDecay(oscEnvDecay);
            oscEnv.setRelease(oscEnvRelease);
            oscEnv.setSustain(oscEnvSustain);
            
            currentFrame+= oscA.getSample(oscAfreq) * oscMix;
            currentFrame+= oscB.getSample(oscBfreq) * (1 - oscMix);
            
            currentFrame = oscEnv.adsr(currentFrame, oscEnv.trigger);
            currentFrame = filter.getFilter(currentFrame, filterCutOffFreq, filterResonance);
            
            const float currentSample = float(currentFrame) * level;

            for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                outputBuffer.addSample (i, startSample, currentSample);
            
            ++startSample;
        }
    }

    void pitchWheelMoved(int) override {}
    void controllerMoved(int, int) override {}


private:
    double level;
    Oscillator oscA, oscB, LFO;
    maxiEnv oscEnv;
    Filter filter;
    double oscMix;
    double oscAfreq, oscBfreq;
    double oscAtune, oscBtune;
    double currentFrame;
    double oscEnvAttack, oscEnvDecay, oscEnvSustain, oscEnvRelease;
    double filterCutOffFreq, filterResonance;
    
    int oscAoct, oscBoct;
    int oscAWaveform, oscBWaveform;


    
};

//==============================================================================
/**
*/
class EmptySynthAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    EmptySynthAudioProcessor();
    ~EmptySynthAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool setPreferredBusArrangement (bool isInput,
                                     int bus,
                                     const AudioChannelSet& preferredSet);
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    // These will be needed.
    SimpleVoice*         voice;
    Synthesiser          synth;
    /* Add parameters when you have parameterised the voicings DSP and you know
     * which variables will need changing.
    AudioParameterInt*   modulationIndexParamter;
    AudioParameterFloat* modulationFrequencyRatioParameter;
    */


    // Used in preparetoplay()
    double lastSampleRate;
    AudioParameterFloat* oscMix;
    AudioParameterFloat* oscAtune;
    AudioParameterFloat* oscBtune;
    AudioParameterFloat* oscEnvAttack;
    AudioParameterFloat* oscEnvDecay;
    AudioParameterFloat* oscEnvSustain;
    AudioParameterFloat* oscEnvRelease;
    AudioParameterFloat* filterCutOffFreq;
    AudioParameterFloat* filterResonance;
    AudioParameterInt* oscAoct;
    AudioParameterInt* oscBoct;
    AudioParameterInt* oscAWaveform;
    AudioParameterInt* oscBWaveform;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EmptySynthAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
