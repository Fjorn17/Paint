#include "pubsub.h"
template<typename T>
bool PubSub<T>::existSubscriber(int subscriberIndex) {
	return(subscriberIndex > -1);
}

template<typename T>
void PubSub<T>::deleteSuscriber(string channel, unsigned int subscriberIndex) {
	auto subscribers = &channels[channel];

	subscribers->erase(subscribers->begin() + subscriberIndex);

	if (isChannelEmpty(channel)) {
		deleteChannel(channel);
	}
}

template<typename T>
int PubSub<T>::findSubscriberIndex(vector<PtrFunction>& arr, PtrFunction subscriber) {
	for (auto index = 0; index < arr.size(); ++index) {
		if (arr[index] == subscriber)
			return index;
	}

	return -1;
}

template<typename T>
bool PubSub<T>::isChannelEmpty(string channel) {
	return (channels[channel].size() == 0);
}