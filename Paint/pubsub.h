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
	void deleteChannel(string  channel);

	void addSubscriberToChannel(PtrFunction subscriber, string channel);
	void deleteSubscriber(PtrFunction subscriber, string channel);

	bool channelExists(string channel);

public:
	void publish(string channel, T data);
	VoidFunction subscribe(string channel, PtrFunction subscriber);
};

#endif//!PUBSUB_H
