#ifndef PUBSUB_H
#define PUBSUB_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <functional>

using namespace std;

typedef function<void()> VoidFunction;

template<typename T>
class PubSub {
	typedef void (*PtrFunction)(T);
private:
	map<string, vector<PtrFunction>> channels;


	bool existSubscriber(int subscriberIndex);
	void deleteSuscriber(string channel, unsigned int subscriberIndex);
	int findSubscriberIndex(vector<PtrFunction>& arr, PtrFunction subscriber);
	

	bool isChannelEmpty(string channel);

	void deleteChannel(string  channel) {
		channels.erase(channel);
	}

	void addSubscriberToChannel(PtrFunction subscriber, string channel) {
		if (!channelExists(channel)) {
			channels[channel] = { subscriber };
		}

		else {
			channels[channel].push_back(subscriber);
		}
	}

	void deleteSubscriber(PtrFunction subscriber, string channel) {
		auto suscriberIndex = findSubscriberIndex(channels[channel], subscriber);
		if (existSubscriber(suscriberIndex)) {
			deleteSuscriber(channel, suscriberIndex);
		}
	}

	bool channelExists(string channel) {
		return (channels.count(channel) == 1);
	}
public:

	void publish(string channel, T data) {
		if (channelExists(channel)) {
			for (auto subscriber : channels[channel]) {
				subscriber(data);
			}
		}
	}

	VoidFunction subscribe(string channel, PtrFunction subscriber) {
		addSubscriberToChannel(subscriber, channel);

		return[=]() {
			deleteSubscriber(subscriber, channel);
		};
	}
};

#endif//!PUBSUB_H
