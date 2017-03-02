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
 */
class SimpleVoice : public SynthesiserVoice
{
public:
    SimpleVoice()
    {
        std::cout << "Instanciated SimpleVoice" << std::endl;
    }

    void setParameters (double /*Parameter 1, e.g: Modulation Index*/,
                        double /*Parameter 2, e.g: LFO Rate*/)
    {

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
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
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
            // Insert DSP here to fill up the buffer!
            const float currentSample = level;

            for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                outputBuffer.addSample (i, startSample, currentSample);

            ++startSample;
        }
    }

    void pitchWheelMoved(int) override {}
    void controllerMoved(int, int) override {}


private:
    // Maximilian objects declared here!
    double frequency;
    double level;
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
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
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
    double               lastSampleRate;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EmptySynthAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
