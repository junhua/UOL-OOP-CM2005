/*
  ==============================================================================

    DeckGUI.h
    Created: 2 Aug 2023 12:41:55am
    Author:  Liu Junhua

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "DJAudioPlayer.h"
//==============================================================================
/*
*/
class DeckGUI  : public Component, public Button::Listener, public Slider::Listener, public FileDragAndDropTarget
{
public:
    DeckGUI(DJAudioPlayer* player);
    ~DeckGUI();

    void paint (juce::Graphics&) override;
    void resized() override;

    void buttonClicked (Button *) override;
    void sliderValueChanged (Slider *slider) override;
    
    bool isInterestedInFileDrag(const StringArray &file) override;
    void filesDropped (const StringArray &files, int x, int y) override;
    
    
private:
    FileChooser fChooser{"Select a file..."};
    
    TextButton playButton{"PLAY"};
    TextButton stopButton{"STOP"};
    TextButton loadButton{"LOAD"};
  
    Slider volSlider;
    Slider speedSlider;
    Slider posSlider;
    
    DJAudioPlayer* player;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DeckGUI)
};
