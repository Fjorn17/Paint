#ifndef SINGLETON_H
#define SINGLETON_H

#include <string>
#include <mutex>

class Singleton {
private:
	static Singleton* instance;
	static std::mutex mutex;

protected:
	Singleton(){}
	~Singleton(){}
	
public:
	Singleton(Singleton &other) = delete;
	void operator=(const Singleton&) = delete;
	
	static Singleton* getInstance();
};



#endif //!SINGLETON_H