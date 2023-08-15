/*
  ==============================================================================

    WaveformDisplay.cpp
    Created: 10 Aug 2023 9:27:26pm
    Author:  Liu Junhua

  ==============================================================================
*/

#include <JuceHeader.h>
#include "WaveformDisplay.h"

//==============================================================================
WaveformDisplay::WaveformDisplay(AudioFormatManager & formatManagerToUse,
                                 AudioThumbnailCache & cacheToUse
                                 ) : audioThumb(1000, formatManagerToUse, cacheToUse),
                                     fileLoaded(false), position(0)
{
    audioThumb.addChangeListener(this);
}

WaveformDisplay::~WaveformDisplay()
{
}

void WaveformDisplay::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
    g.setColour (juce::Colours::orange);
    
    if (fileLoaded){
        audioThumb.drawChannel(g, getLocalBounds(), 0, audioThumb.getTotalLength(), 0, 1.0f);
        g.setColour(Colours::lightgreen);
        g.drawRect(position * getWidth(), 0, getWidth()/20, getHeight());
    }else {
        g.setFont (20.0f);
        g.drawText ("File not loaded", getLocalBounds(),
                    juce::Justification::centred, true);   // draw some placeholder text
    }
}

void WaveformDisplay::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void WaveformDisplay::loadURL(URL audioURL) {
    audioThumb.clear();
    fileLoaded = audioThumb.setSource(new URLInputSource(audioURL));
    
    if (fileLoaded) {
        std::cout << "wfd: loaded!" << std::endl;
        repaint();
    } else{
        std::cout << "wfd: not loaded!" << std::endl;
    }
}


void WaveformDisplay::changeListenerCallback(ChangeBroadcaster *source){
    std::cout << "wfd: change received!" << std::endl;
    repaint();
}

void WaveformDisplay::setPositionRelative(double pos){
    if(pos!=position){
        repaint();
    }
    position = pos;
}
