// C++ 101 de chillin - Sesión 4
// https://youtu.be/2MfsjLpTIZc
// https://www.twitch.tv/videos/966204946

#include <cstdio>
#include <iostream>
#include <cstdint>
#include <memory>

class Friend {
public:
    Friend(const std::string& name) : m_name(name) {
        printf("Friend's ctor\n");
    }

    virtual ~Friend() {
        printf("Friend's dtor\n");
    }

    virtual bool remembersYourBirthday() {
        return false;
    }

    std::string getName() const {
        return m_name;
    }

    bool isReal() const {
        m_name = "isReal";
        return true;
    }

private:
    mutable std::string m_name;
};

class PastelDeCarne {
public:
    char m_buffer[128];
};

class IHeavy {
public:
    virtual bool isHeavy() = 0;
};

class Murcian : virtual public Friend {
public:
    Murcian(const std::string& name) : Friend("Murcian") {}

private:
    PastelDeCarne m_pastelico;
};

class BestFriend : virtual public Friend, public IHeavy, public Murcian {
public:
    BestFriend(const std::string& name) : Friend(name), Murcian(name) {
        printf("BestFriend's ctor\n");
    }

    ~BestFriend() {
        printf("BestFriend's dtor\n");
    }

    virtual bool remembersYourBirthday() override {
        return true;
    }

    virtual bool isHeavy() override {
        return true;
    }
};

int main(int argc, char *argv[])
{
    // auto jorge = std::unique_ptr<BestFriend>(new BestFriend("Jorge")); // the same as the next line
    // Friend* jorge = new BestFriend("Jorge");
    auto jorge = std::make_unique<BestFriend>("Jorge");
    Friend *maria = new BestFriend("María");
    printf("sizeof Friend = %zu\n", sizeof(Friend));
    printf("Friend name is %s and remembers your birthday %s. Btw, isHeavy %s\n",
            jorge->getName().c_str(),
            jorge->remembersYourBirthday() ? "yas!" : "nope!",
            jorge->isHeavy() ? "\\m/" : ":(");

    Friend *jorgeFriend = static_cast<Friend*>(jorge.get());
    BestFriend *jorgeBestFriend = dynamic_cast<BestFriend*>(jorgeFriend);
    // reinterpret_cast (== cast de C) -> reinterpret_cast<void*> == (void*)
    // const_cast

    printf("Jorge's friend name: %s, sizeof %zu\n", jorgeFriend->getName().c_str(), sizeof(*jorgeFriend));
    printf("Jorge's BFF name: %s, sizeof %zu\n", jorgeBestFriend->getName().c_str(), sizeof(*jorgeBestFriend));
    const Murcian murcian("Ginés");
    printf("Murcian's name %s\n", murcian.getName().c_str());
    const_cast<Murcian&>(murcian).remembersYourBirthday();

    delete maria;

    return 0;
}
