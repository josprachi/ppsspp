// MIDI input utilities.
//
// Currently, this is just a platform-clean wrapper around the Win32 MIDI input facilities.
// Thus, it only supports Windows. Other platforms will get an empty list of midi in devices.

#include <vector>
#include <string>


typedef void *MidiDevice;

// Listeners inherit from this. Pass them into MidiInStart.
class MidiListener
{
public:
	virtual void midiEvent(const uint8_t *cmd);
};

// Gets the names of the devices in a vector. The device identifier is the index in the vector.
std::vector<std::string> MidiInGetDevices();

MidiDevice MidiInStart(int deviceID, MidiListener *listener);
void MidiInStop(MidiDevice device);