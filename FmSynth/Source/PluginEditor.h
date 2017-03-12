/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class EmptySynthAudioProcessorEditor  : public AudioProcessorEditor,
                                        public Slider::Listener
{
public:
    EmptySynthAudioProcessorEditor (EmptySynthAudioProcessor&);
    ~EmptySynthAudioProcessorEditor();

    //==============================================================================
    void                     paint (Graphics&) override;
    void                     resized() override;
    void                     sliderValueChanged (Slider*) override;

private:
    AudioProcessorParameter* getParameter (const String& paramId);
    float                    getParameterValue (const String& paramId);
    void                     setParameterValue (const String& paramId, float value);

    EmptySynthAudioProcessor& processor;

     Slider modulationIndex, modulationFrequency;
     

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EmptySynthAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
