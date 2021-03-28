// C++ 101 de chillin - Sesión 1
// https://youtu.be/1EQbJcWcpus
// https://www.twitch.tv/videos/904598376
//
// Twitter: @pablomarc0s y @BytesAndHumans
// Twitch: https://www.twitch.tv/nietmetal
// Youtube: https://www.youtube.com/channel/UCl_nn643qHc9_jnuskaXCGA


#include <cstdio>
#include <cstdint>

class Ninonino {
public:
    uint32_t m_a = 0;
};

int main(int argc, char *argv[])
{
    int a = 10;
    uint8_t byte;
    printf("Hello WOrld: %d\n", a);

    Ninonino teclita;
    printf("sizeof(Ninonino) = %zu, m_a = %d\n", sizeof(teclita), teclita.m_a);
}
