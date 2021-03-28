// C++ 101 de chillin - Sesión 2
// https://youtu.be/2IRLYfz_k48
// https://www.twitch.tv/videos/922795945

#include <cstdio>
#include <iostream>
#include <cstdint>
#include <memory>

class Param {
public:
    Param() = default;
    explicit Param(uint32_t a) : m_a(a) {
        printf("Param ctor with a = %d\n", m_a);
    }

    uint32_t m_a;
};

class Ninonino {
public:
    Ninonino() :
        m_a(getStaticValue()),
        m_buffer(new uint8_t[128])
    {
        printf("Ninonino default ctor\n");
    }

    Ninonino(Param param) : m_a(param.m_a) {
    }

    ~Ninonino() {
        printf("Ninonino dtor\n");
    }

    uint32_t getA() {
        return m_a;
    }

    uint32_t getA() const {
        return m_a + 1;
    }

    uint32_t method(uint32_t& param) {
        printf("method with param %u\n", param);
        return param;
    }

    static uint32_t getStaticValue() {
        return 5;
    }

private:
    uint32_t m_a;
    uint32_t m_b; // if I remove this, same sizeof
    std::unique_ptr<uint8_t[]> m_buffer; // smart pointer
};

int main(int argc, char *argv[])
{
    printf("Hello World\n");

    {
        printf("Scope beginning\n");
        Ninonino teclita;
        printf("Sizeof teclita = %zu bytes\n", sizeof(teclita));
        printf("Scope end\n");
        uint32_t myValue = 34;
        teclita.method(myValue);
    }

    /*const Ninonino constTeclita;
    Param p;
    Ninonino teclita(p);
    printf("sizeof(Ninonino) = %zu, m_a = %d\n", sizeof(teclita), teclita.getA());
    printf("sizeof(Ninonino) = %zu, m_a = %d\n", sizeof(constTeclita), constTeclita.getA());
    printf("Static %d\n", Ninonino::getStaticValue());
    printf("Static from instance %d\n", teclita.getStaticValue());*/

    return 0;
}
