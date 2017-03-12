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
    SimpleVoice() :
        carrierFrequency(1000),
        modulatorFreq(5),
        modulatorIndex(1000)
    {
        std::cout << "Instanciated SimpleVoice" << std::endl;
    }

    void setParameters (double modFreq,
                        double modIndex)
    {
        modulatorFreq = modFreq;
        modulatorIndex = modIndex;
        
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
        carrierFrequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        level = velocity;
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

            const double modulatorFrame = modulator.sinewave(modulatorFreq);

            double audioFrame = carrier.sinewave (carrierFrequency + modulatorFrame * modulatorIndex);
            
            const float currentSample = float(audioFrame) * level;

            for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                outputBuffer.addSample (i, startSample, currentSample);
            
            ++startSample;
        }
    }

    void pitchWheelMoved(int) override {}
    void controllerMoved(int, int) override {}


private:
    double level;
    maxiOsc carrier, modulator;
    maxiEnv adsrEnv;
    double carrierFrequency;
    double modulatorFreq;
    double modulatorIndex;


    
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
    AudioParameterFloat* modulationFrequencyParameter;
    AudioParameterFloat* modulationIndexParameter;

    // Used in preparetoplay()
    double               lastSampleRate;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EmptySynthAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
