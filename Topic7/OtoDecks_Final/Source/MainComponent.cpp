/*
 ==============================================================================
 
 This file was auto-generated!
 
 ==============================================================================
 */

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);
    
    // Some platforms require permissions to open input channels so request that here
    if (RuntimePermissions::isRequired (RuntimePermissions::recordAudio)
        && ! RuntimePermissions::isGranted (RuntimePermissions::recordAudio))
    {
        RuntimePermissions::request (RuntimePermissions::recordAudio,
                                     [&] (bool granted) { if (granted)  setAudioChannels (2, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (0, 2);
    }
    
    addAndMakeVisible(playButton);
    addAndMakeVisible(stopButton);
    addAndMakeVisible(loadButton);
    
    addAndMakeVisible(volSlider);
    addAndMakeVisible(speedSlider);
    
    playButton.addListener(this);
    stopButton.addListener(this);
    loadButton.addListener(this);
    
    volSlider.addListener(this);
    speedSlider.addListener(this);
    
    volSlider.setRange(0., 1.);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    phase = 0.0;
    dphase = 0.0001;
    
    formatManager.registerBasicFormats();
    
    transportSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
    resampleSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    resampleSource.getNextAudioBlock(bufferToFill);
}

void MainComponent::releaseResources()
{
    transportSource.releaseResources();
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    
    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    double rowH = getHeight() / 5;
    playButton.setBounds(0, 0, getWidth(), rowH);
    stopButton.setBounds(0, rowH, getWidth(), rowH);
    
    volSlider.setBounds(0, rowH * 2, getWidth(), rowH);
      
    speedSlider.setBounds(0, rowH * 3, getWidth(), rowH);
    loadButton.setBounds(0, rowH * 4, getWidth(), rowH);
}

void MainComponent::buttonClicked(Button * button) {
    if (button == &playButton){
        
        std::cout << "Start Button" << std::endl;
        transportSource.start();
    }
    if (button == &stopButton){
        transportSource.stop();
    }
    if (button == &loadButton){
        auto fileChooserFlags =
        FileBrowserComponent::canSelectFiles;
        
        fChooser.launchAsync(fileChooserFlags, [this](const FileChooser& chooser){
            File chosenFile = chooser.getResult();
            
            loadURL(URL{chosenFile});
        });
    }
}

void MainComponent::sliderValueChanged(Slider * slider) {
    if (slider == &volSlider) {
        transportSource.setGain(slider->getValue());
    }
    if (slider == &speedSlider) {
        resampleSource.setResamplingRatio(slider->getValue());
    }
}

void MainComponent::loadURL(URL audioURL){
    
    auto* reader = formatManager.createReaderFor(audioURL.createInputStream(false));
    if(reader != nullptr){
        std::cout << "File loaded successfully!" << std::endl;
        
        std::unique_ptr<AudioFormatReaderSource> newSource (new AudioFormatReaderSource(reader, true));
        transportSource.setSource(newSource.get(), 0, nullptr, reader->sampleRate );
        readerSource.reset(newSource.release());
        
    } else {
        std::cout << "Failed to load file!" << std::endl;

    }
}
