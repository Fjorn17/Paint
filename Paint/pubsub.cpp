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

template<typename T>
void PubSub<T>::deleteChannel(string  channel) {
	channels.erase(channel);
}
template<typename T>
void PubSub<T>::addSubscriberToChannel(PtrFunction subscriber, string channel) {
	if (!channelExists(channel)) {
		channels[channel] = { subscriber };
	}

	else {
		channels[channel].push_back(subscriber);
	}
}

template<typename T>
void PubSub<T>::deleteSubscriber(PtrFunction subscriber, string channel) {
	auto suscriberIndex = findSubscriberIndex(channels[channel], subscriber);
	if (existSubscriber(suscriberIndex)) {
		deleteSuscriber(channel, suscriberIndex);
	}
}

template<typename T>
bool PubSub<T>::channelExists(string channel) {
	return (channels.count(channel) == 1);
}

template<typename T>
void PubSub<T>::publish(string channel, T data) {
	if (channelExists(channel)) {
		for (auto subscriber : channels[channel]) {
			subscriber(data);
		}
	}
}


template<typename T>
VoidFunction PubSub<T>::subscribe(string channel, PtrFunction subscriber) {
	addSubscriberToChannel(subscriber, channel);

	return[=]() {
		deleteSubscriber(subscriber, channel);
	};
}