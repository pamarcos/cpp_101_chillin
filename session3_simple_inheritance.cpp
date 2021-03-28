// C++ 101 de chillin - Sesión 3
// https://youtu.be/Ag4nsxuk2JU
// https://www.twitch.tv/videos/948941528
//
// Twitter: @pablomarc0s y @BytesAndHumans
// Twitch: https://www.twitch.tv/nietmetal
// Youtube: https://www.youtube.com/channel/UCl_nn643qHc9_jnuskaXCGA

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

private:
    std::string m_name;
};

class PastelDeCarne {};

class IHeavy {
public:
    virtual bool isHeavy() = 0;
};

class BestFriend : public Friend, public IHeavy {
public:
    BestFriend(const std::string& name) : Friend(name) {
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
    printf("Jorge's friend name: %s, sizeof %zu\n", jorgeFriend->getName().c_str(), sizeof(*jorgeFriend));
    printf("Jorge's friend name: %s, sizeof %zu\n", jorgeBestFriend->getName().c_str(), sizeof(*jorgeBestFriend));

    delete maria;

    return 0;
}
