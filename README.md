# C++ 101 de chillin

## Qué y quiénes

Elena quiere aprender C++ y como estamos pandemia (what a time to be alive),
decide juntarse virtualmente con Pablo en un streaming para hacer un poco de
ninonino ninoní de C++.

Github: [@elenatorro](https://github.com/elenatorro) y
[@pamarcos](https://github.com/pamarcos/https://github.com/pamarcos/)

Twitter: [@BytesAndHumans](https://twitter.com/BytesAndHumans) y
[@pablomarc0s](https://twitter.com/pablomarc0s)


## Cómo compilar

En las distros de Linux Debian-based como Ubuntu,

```
sudo apt install build-essential
```

instala tanto gcc, g++, make, bintools y el linker para empezar a funcionar.
Luego, echamos a andar make a y funcionar:

```
make
```

## Sesión 1

https://youtu.be/1EQbJcWcpus - https://www.twitch.tv/videos/904598376

Nos presentamos y comentamos que C++ tiene un runtime (aunque pequeño),
necesario para ejecutar aplicaciones escritas en C++.

Hacemos el setup de un proyecto sencillo con un Makefile (por favor, no uséis
Makefile's en el siglo XXI para proyectos de más de 1 fichero) que utiliza el
address y undefined sanitizer para asegurarnos que hacemos acrobacias pero con
red de seguridad: https://clang.llvm.org/docs/AddressSanitizer.html

Creamos nuestra primera clase con un miembro y ya.

## Sesión 2

https://youtu.be/2IRLYfz_k48 - https://www.twitch.tv/videos/922795945

Ampliamos nuestra clase `Ninonino` con más miembros. Explicamos lo que son los
constructores (y cuándo debemos usar explicit) y los destructores. Además,
presentamos los valores y métodos estáticos. Para cerrar, hablamos de los
scopes y de que deberíamos usar std::unique_ptr (desde C++11) en vez de raw
pointers para evitar memory leaks.

## Sesión 3

https://youtu.be/Ag4nsxuk2JU - https://www.twitch.tv/videos/948941528

First things first. Elena se olvida de que es mi cumpleaños y por supuestísimo
se lleva el escarnio público merecido :P. Por fin entramos al turrón con la
herencia de clases, cómo hacer interfaces. Comentamos qué son los métodos
virtuales y para qué sirven. Regla importante: si una clase está pensada para
que alguien herede de ella, tenemos que declarar su destructor como virtual.

## Sesión 4

https://youtu.be/2MfsjLpTIZc - https://www.twitch.tv/videos/966204946

Cerramos la última sesión teórica de C++ explicando herencia múltiple y las
movidas que acarrea, como por ejemplo el problema del diamante:
https://en.wikipedia.org/wiki/Multiple_inheritance#The_diamond_problem

**Por fin** hablamos de templates, de cómo nos sirve para reutilizar el mismo
código para distintos tipos.
