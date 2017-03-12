/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
EmptySynthAudioProcessor::EmptySynthAudioProcessor()
{
    /* Add parameters and then add the necessary voices and sounds.
    addParameter (modulationIndexParamter = new AudioParameterInt ("ModIndex",
                                                                   "Modulation Index",
                                                                   0, 1500, 0));
    addParameter (modulationFrequencyRatioParameter = new AudioParameterFloat ("ModFreqRatio",
                                                                               "Modulation Frequency Ratio",
                                                                               -3.8, 3.8, 0));
    synth.clearVoices();
    for (int i = 0; i < maxNumVoices; ++i)
        synth.addVoice(new SimpleVoice());

    synth.clearSounds();
    synth.addSound(new SimpleSound());
    */
    
    addParameter (oscMix=new AudioParameterFloat ("oscMix", "Oscillator Mix", 0, 1 , 0.5));
    addParameter (oscAtune=new AudioParameterFloat ("oscATune", "Osc A Tune", -1, 1, 0));
    addParameter (oscBtune=new AudioParameterFloat ("oscBTune", "Osc B Tune", -1, 1, 0));
    addParameter (oscEnvAttack=new AudioParameterFloat("oscEnvAttack", "Attack", 0, 5000, 1000));
    addParameter (oscEnvDecay=new AudioParameterFloat ("oscEnvDecay", "Decay", 0, 3000, 100));
    addParameter (oscEnvSustain=new AudioParameterFloat ("oscEnvSustain", "Sustain", 0, 1, 1));
    addParameter (oscEnvRelease=new AudioParameterFloat ("oscEnvRelease", "Release", 0, 5000, 1000));
    addParameter (filterCutOffFreq=new AudioParameterFloat ("filterCutOffFreq", "Filter Cut Off Frequency", 1, 20000,400));
    addParameter (filterResonance=new AudioParameterFloat ("filterResonance", "Filter Resonance", 1, 60, 1));
    addParameter (oscAoct=new AudioParameterInt ("oscAoct", "Oscillator A Octave", -3, 3, 0));
    addParameter (oscBoct=new AudioParameterInt ("oscBoct", "Oscillator B Octave", -3, 3, 0));
    addParameter (oscAWaveform=new AudioParameterInt ("oscAWaveform", "Oscillator A Waveform", 0, 4, 0));
    addParameter (oscBWaveform=new AudioParameterInt ("oscBWaveform", "Oscillator B Waveform", 0, 4, 0));
    

    synth.clearVoices();
    for (int i = 0; i < 1; ++i)
        synth.addVoice(new SimpleVoice());
    
    synth.clearSounds();
    synth.addSound(new SimpleSound());
}

EmptySynthAudioProcessor::~EmptySynthAudioProcessor()
{
}

//==============================================================================
const String EmptySynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool EmptySynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool EmptySynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double EmptySynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int EmptySynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int EmptySynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void EmptySynthAudioProcessor::setCurrentProgram (int index)
{
}

const String EmptySynthAudioProcessor::getProgramName (int index)
{
    return String();
}

void EmptySynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void EmptySynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need... Maybe something like this:
    
    ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    synth.setCurrentPlaybackSampleRate(lastSampleRate);
    maxiSettings::setup(lastSampleRate, getTotalNumOutputChannels(), samplesPerBlock);
    
    
}

void EmptySynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool EmptySynthAudioProcessor::setPreferredBusArrangement (bool                   isInput,
                                                           int                    bus,
                                                           const AudioChannelSet& preferredSet)
{
    // Reject any bus arrangements that are not compatible with your plugin

    const int numChannels = preferredSet.size();

   #if JucePlugin_IsMidiEffect
    if (numChannels != 0)
        return false;
   #elif JucePlugin_IsSynth
    if (isInput || (numChannels != 1 && numChannels != 2))
        return false;
   #else
    if (numChannels != 1 && numChannels != 2)
        return false;

    if (! AudioProcessor::setPreferredBusArrangement (! isInput, bus, preferredSet))
        return false;
   #endif

    return setPreferredBusArrangement (isInput, bus, preferredSet);
}
#endif

void EmptySynthAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    /* Here I would loop through the voices added to the synth, assure they are
     * a voicing I want through the use of dynamic pointer casting, and then
     * set the voice member fields to whatever the parameters are.
   
    */

    // Clear the buffer incase there is any garbage, this shouldn't really be
    // necessary as we should be filling this up entirely...
    // buffer.clear();

    /* This is where we call the synth and get all of the voicings dsp audio
     * and add it to the buffer being passed in via reference.
    synth.renderNextBlock(buffer,
                          midiMessages,
                          0,
                          buffer.getNumSamples());
     */
    
    for (int i = synth.getNumVoices(); --i >= 0;)
    {
        if ((voice = dynamic_cast<SimpleVoice*>(synth.getVoice(i))))
        {
            voice->setParameters(double(oscEnvAttack->get()),
                                 double(oscEnvDecay->get()),
                                 double(oscEnvSustain->get()),
                                 double(oscEnvRelease->get()),
                                 double(filterCutOffFreq->get()),
                                 double(filterResonance->get()),
                                 int(oscAWaveform->get()),
                                 int(oscBWaveform->get()),
                                 int(oscAoct->get()),
                                 int(oscBoct->get()),
                                 double(oscMix->get()));
                    
        }
    }
    
    buffer.clear();
    synth.renderNextBlock(buffer,
                          midiMessages,
                          0,
                          buffer.getNumSamples());
    
    
}

//==============================================================================
bool EmptySynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* EmptySynthAudioProcessor::createEditor()
{
    return new EmptySynthAudioProcessorEditor (*this);
}

//==============================================================================
void EmptySynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    MemoryOutputStream stream(destData, true);

    /* For example this might be used to store parameters.
    stream.writeFloat(*modulationIndexParamter);
    stream.writeFloat(*modulationFrequencyRatioParameter);
    */
}

void EmptySynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.

    /* This would be used to get parameters.
    modulationIndexParamter->setValueNotifyingHost(stream.readFloat());
    modulationFrequencyRatioParameter->setValueNotifyingHost(stream.readFloat());
    */
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new EmptySynthAudioProcessor();
}
