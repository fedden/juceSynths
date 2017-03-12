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
    
    oscMix.setName("oscMix");
    oscMix.addListener(this);
    oscMix.setSliderStyle (Slider::LinearBarVertical);
    oscMix.setRange(0.0, 1.0, 0.0);
    oscMix.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    oscMix.setPopupDisplayEnabled(true, this);
    oscMix.setValue(0.5);
    addAndMakeVisible(oscMix);
    
    oscAtune.setName("oscAtune");
    oscAtune.addListener(this);
    oscAtune.setSliderStyle (Slider::LinearBarVertical);
    oscAtune.setRange(-1.0, 1.0, 0.0);
    oscAtune.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    oscAtune.setPopupDisplayEnabled(true, this);
    oscAtune.setValue(0.0);
    addAndMakeVisible(oscAtune);
    
    oscAtune.setName("oscBtune");
    oscAtune.addListener(this);
    oscAtune.setSliderStyle (Slider::LinearBarVertical);
    oscAtune.setRange(-1.0, 1.0, 0.0);
    oscAtune.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    oscAtune.setPopupDisplayEnabled(true, this);
    oscAtune.setValue(0.0);
    addAndMakeVisible(oscBtune);
    
    oscEnvAttack.setName("oscEnvAttack");
    oscEnvAttack.addListener(this);
    oscEnvAttack.setSliderStyle (Slider::LinearBarVertical);
    oscEnvAttack.setRange(0.0, 5000.0, 0.0);
    oscEnvAttack.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    oscEnvAttack.setPopupDisplayEnabled(true, this);
    oscEnvAttack.setTextValueSuffix("ms");
    oscEnvAttack.setValue(1000.0);
    addAndMakeVisible(oscEnvAttack);
    
    oscEnvDecay.setName("oscEnvDecay");
    oscEnvDecay.addListener(this);
    oscEnvDecay.setSliderStyle (Slider::LinearBarVertical);
    oscEnvDecay.setRange(0.0, 3000.0, 0.0);
    oscEnvDecay.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    oscEnvDecay.setPopupDisplayEnabled(true, this);
    oscEnvDecay.setTextValueSuffix("ms");
    oscEnvDecay.setValue(1500.0);
    addAndMakeVisible(oscEnvDecay);
    
    oscEnvSustain.setName("oscEnvSustain");
    oscEnvSustain.addListener(this);
    oscEnvSustain.setSliderStyle (Slider::LinearBarVertical);
    oscEnvSustain.setRange(0.0, 1.0, 0.0);
    oscEnvSustain.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    oscEnvSustain.setPopupDisplayEnabled(true, this);
    oscEnvSustain.setTextValueSuffix("level");
    oscEnvSustain.setValue(1.0);
    addAndMakeVisible(oscEnvSustain);
    
    oscEnvRelease.setName("oscEnvRelease");
    oscEnvRelease.addListener(this);
    oscEnvRelease.setSliderStyle (Slider::LinearBarVertical);
    oscEnvRelease.setRange(0.0, 5000.0, 0.0);
    oscEnvRelease.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    oscEnvRelease.setPopupDisplayEnabled(true, this);
    oscEnvRelease.setTextValueSuffix("ms");
    oscEnvRelease.setValue(1000.0);
    addAndMakeVisible(oscEnvRelease);
    
    filterCutOffFreq.setName("filterCutOffFrequency");
    filterCutOffFreq.addListener(this);
    filterCutOffFreq.setSliderStyle (Slider::LinearBarVertical);
    filterCutOffFreq.setRange(1.0, 20000.0, 0.0);
    filterCutOffFreq.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    filterCutOffFreq.setPopupDisplayEnabled(true, this);
    filterCutOffFreq.setTextValueSuffix("Hertz");
    filterCutOffFreq.setValue(4000);
    addAndMakeVisible(filterCutOffFreq);
    
    filterResonance.setName("Filter Resonance");
    filterResonance.addListener(this);
    filterResonance.setSliderStyle (Slider::LinearBarVertical);
    filterResonance.setRange(1.0, 60, 0.0);
    filterResonance.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    filterResonance.setPopupDisplayEnabled(true, this);
    filterResonance.setTextValueSuffix(" % Gnarly");
    filterResonance.setValue(1.0);
    addAndMakeVisible(filterResonance);
    
    oscAoct.setName("Osc A Octave");
    oscAoct.addListener(this);
    oscAoct.setSliderStyle (Slider::LinearBarVertical);
    oscAoct.setRange(-3.0, 3.0, 1.0);
    oscAoct.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    oscAoct.setPopupDisplayEnabled(true, this);
    oscAoct.setValue(0.0);
    addAndMakeVisible(oscAoct);
    
    oscBoct.setName("Osc B Octave");
    oscBoct.addListener(this);
    oscBoct.setSliderStyle (Slider::LinearBarVertical);
    oscBoct.setRange(-3.0, 3.0, 1.0);
    oscBoct.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    oscBoct.setPopupDisplayEnabled(true, this);
    oscBoct.setValue(0.0);
    addAndMakeVisible(oscBoct);
    
    oscAWaveform.setName("Osc A Waveform");
    oscAWaveform.addListener(this);
    oscAWaveform.setSliderStyle (Slider::LinearBarVertical);
    oscAWaveform.setRange(0.0, 4.0, 1.0);
    oscAWaveform.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    oscAWaveform.setPopupDisplayEnabled(true, this);
    oscAWaveform.setValue(0.0);
    addAndMakeVisible(oscAWaveform);
    
    oscBWaveform.setName("Osc B Waveform");
    oscBWaveform.addListener(this);
    oscBWaveform.setSliderStyle (Slider::LinearBarVertical);
    oscBWaveform.setRange(0.0, 4.0, 1.0);
    oscBWaveform.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    oscBWaveform.setPopupDisplayEnabled(true, this);
    oscBWaveform.setValue(0.0);
    addAndMakeVisible(oscBWaveform);
    
   
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


    oscMix.setBounds(0 * getWidth()/12, 30, 20, getHeight() - 60);
    oscAtune.setBounds(1 * getWidth()/12, 30, 20, getHeight() - 60);
    oscBtune.setBounds(2 * getWidth()/12, 30, 20, getHeight() - 60);
    oscEnvAttack.setBounds(3 * getWidth()/12, 30, 20, getHeight() - 60);
    oscEnvDecay.setBounds(4 * getWidth()/12, 30, 20, getHeight() - 60);
    oscEnvSustain.setBounds(5 * getWidth()/12, 30, 20, getHeight() - 60);
    oscEnvRelease.setBounds(6 * getWidth()/12, 30, 20, getHeight() - 60);
    filterCutOffFreq.setBounds(7 * getWidth()/12, 30, 20, getHeight() - 60);
    filterResonance.setBounds(8 * getWidth()/12, 30, 20, getHeight() - 60);
    oscAoct.setBounds(9 * getWidth()/12, 30, 20, getHeight() - 60);
    oscBoct.setBounds(10 * getWidth()/12, 30, 20, getHeight() - 60);
    oscAWaveform.setBounds(11 * getWidth()/12, 30, 20, getHeight() - 60);
    oscBWaveform.setBounds(12 * getWidth()/12, 30, 20, getHeight() - 60);

    
}

void EmptySynthAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    
    if (slider->getName() == "oscMix")
    {
        setParameterValue("oscMix", oscMix.getValue());
    }
    else if (slider->getName() == "oscAtune")
    {
        setParameterValue("oscAtune", oscAtune.getValue());
    }
    else if (slider->getName() == "oscBtune")
    {
        setParameterValue("oscBtune", oscBtune.getValue());
    }
    else if (slider->getName() == "oscEnvAttack")
    {
        setParameterValue("oscEnvAttack", oscEnvAttack.getValue());
    }
    else if (slider->getName() == "oscEnvDecay")
    {
        setParameterValue("oscEnvDecay", oscEnvDecay.getValue());
    }
    else if (slider->getName() == "oscEnvSustain")
    {
        setParameterValue("oscEnvSustain", oscEnvSustain.getValue());
    }
    else if (slider->getName() == "oscEnvRelease")
    {
        setParameterValue("oscEnvRelease", oscEnvRelease.getValue());
    }
    else if (slider->getName() == "filterCutoffFreq")
    {
        setParameterValue("filterCutOffFreq", filterCutOffFreq.getValue());
    }else if (slider->getName() == "filterResonance")
    {
        setParameterValue("filterResonance", filterResonance.getValue());
    }
    else if (slider->getName() == "Osc A Octave")
    {
        setParameterValue("oscAoct", oscAoct.getValue());
    }
    else if (slider->getName() == "Osc B Octave")
    {
        setParameterValue("oscBoct", oscBoct.getValue());
    }
    else if (slider->getName() == "Osc A Waveform")
    {
        setParameterValue("oscAWaveform", oscAWaveform.getValue());
    }
    else if (slider->getName() == "Osc B Waveform")
    {
        setParameterValue("oscBWaveform", oscBWaveform.getValue());
    }
    
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
