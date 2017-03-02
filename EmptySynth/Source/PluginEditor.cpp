/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
EmptySynthAudioProcessorEditor::EmptySynthAudioProcessorEditor (EmptySynthAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    /* For each slider, you will need to do pretty much all of this. Obviously
     * not everything, and there will need to be some customisation here and
     * there.

    modulationIndex.setName("ModIndex");
    modulationIndex.addListener(this);
    modulationIndex.setSliderStyle (Slider::LinearBarVertical);
    modulationIndex.setRange(0.0, 1500.0, 0.0);
    modulationIndex.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    modulationIndex.setPopupDisplayEnabled(true, this);
    modulationIndex.setTextValueSuffix(" % Gnarly");
    modulationIndex.setValue(0.0);

    addAndMakeVisible(modulationIndex);
     */
}

EmptySynthAudioProcessorEditor::~EmptySynthAudioProcessorEditor()
{
}

//==============================================================================
void EmptySynthAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("My rad synth.", getLocalBounds(), Justification::centred, 1);
}

void EmptySynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    // Heres how I might position a slider.
    // modulationIndex.setBounds(40, 30, 20, getHeight() - 60);
}

void EmptySynthAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    /* Here is how I set parameters if the editor changes them.
    if (slider->getName() == "ModIndex")
    {
        setParameterValue("ModIndex", modulationIndex.getValue());
    }
    else if (slider->getName() == "ModFreqRatio")
    {
        setParameterValue("ModFreqRatio", modulationFrequencyRatio.getValue());
    }
    */
}

// Keep everything below this line, it's all useful.
AudioProcessorParameter* EmptySynthAudioProcessorEditor::getParameter (const String& paramId)
{
    if (AudioProcessor* processor = getAudioProcessor())
    {
        const OwnedArray<AudioProcessorParameter>& params = processor->getParameters();

        for (int i = 0; i < params.size(); ++i)
        {
            if (AudioProcessorParameterWithID* param = dynamic_cast<AudioProcessorParameterWithID*> (params[i]))
            {
                if (param->paramID == paramId)
                    return param;
            }
        }
    }

    return nullptr;
}

float EmptySynthAudioProcessorEditor::getParameterValue (const String& paramId)
{
    if (AudioProcessorParameter* param = getParameter (paramId))
        return param->getValue();

    return 0.0f;
}

void EmptySynthAudioProcessorEditor::setParameterValue (const String& paramId, float value)
{
    if (AudioProcessorParameter* param = getParameter (paramId))
        param->setValueNotifyingHost (value);
}
