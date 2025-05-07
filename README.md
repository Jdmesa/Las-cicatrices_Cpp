# ⚔️ Las Cicatrices del Valle 🌲🌋

¡Bienvenido al mundo de "Las Cicatrices del Valle"! Este proyecto es una simulación de un ecosistema lleno de criaturas fantásticas, desarrollado con mucho cariño en C++. Originalmente, fue nuestro campo de batalla para la asignatura de Programación Orientada a Objetos, donde pusimos a prueba nuestros conocimientos sobre herencia, polimorfismo y cómo organizar un montón de código para que cobre vida. 🧙‍♂️

Imagina un mundo que se crea solo, donde seres como dragones, enanos, hadas y gigantes luchan por sobrevivir. Se mueven, se encuentran, a veces pelean, evolucionan ¡e incluso pueden convertirse en zombies! 🧟 Todo esto sucede en un mapa con diferentes paisajes, desde bosques misteriosos hasta volcanes humeantes.

Nuestro objetivo era simple pero desafiante: crear un pequeño universo digital donde pudiéramos ver cómo interactúan estos seres y cómo cambian con el tiempo, ¡todo gracias a la magia de la programación!

## 🧑‍💻 El Equipo detrás del Valle 🤝

Somos un trío de aventureros del código que se unió para dar vida a este valle:

* **Jose David Mesa (Líder del Pelotón)** 👑: Guiando la estrategia y asegurándose de que todas las piezas encajaran.
* **Jose David Gonzalez (El Arquitecto de Mundos)** 🗺️: Contribuyendo al diseño y la lógica del ecosistema.
* **Julian Hurtado (El Herrero de Criaturas)** 🛠️: Forjando las criaturas y sus habilidades únicas.

Juntos, enfrentamos los desafíos de la programación para traerles esta simulación.

## 📜 ¿De qué va el juego? (Un vistazo rápido) 👀

En "Las Cicatrices del Valle", no hay un objetivo final más que observar la vida (¡y la no-vida!) desarrollarse. Es como tener tu propio terrario digital de fantasía.

### 🐾 Criaturas del Valle:

Te encontrarás con seres variados, cada uno con su toque especial:

* 🐉 **Dragones:** ¡Majestuosos y temibles! Escupen fuego, pueden volar grandes distancias 💨 y tienen una piel tan dura que regeneran su vida ❤️.
* ⛏️ **Enanos:** Pequeños pero matones. Expertos en dar picotazos y también pueden regenerar algo de vida ❤️.
* ✨ **Hadas:** Seres mágicos y etéreos. Pueden volverse casi invisibles 👻, lo que las hace difíciles de dañar, y atacan con hechizos.
* 👣 **Gigantes:** ¡Enormes y con muchísima vida! Aunque son fuertes, ten en cuenta que, por ahora, no aparecen automáticamente al inicio de la simulación. ¡Quizás en una futura expedición!

### 🗺️ Explorando el Valle (¿Qué puedes hacer?):

* **🌍 Elige tu Aventura:** Al empezar, decides si quieres un entorno **Boscoso** 🌲 (con zonas densas, claras u oscuras) o **Volcánico** 🌋 (con rocas, cenizas o fumarolas).
* **✨ Un Mundo Siempre Nuevo:** El mapa y las primeras criaturas se generan al azar. ¡Cada partida es diferente! El tamaño del mapa también es una sorpresa (entre 5x5 y 15x15).
* **⏳ La Vida Sigue su Curso:** La simulación avanza por turnos (ciclos). En cada turno:
    * **Movimiento 🚶‍♀️:** Las criaturas exploran el mapa.
    * **Combate ⚔️:** Si dos o más criaturas se topan en la misma casilla, ¡se arma la pelea! Dos de ellas pelearán, y el resultado dependerá de sus habilidades.
    * **Evolución o Muerte 📈💀:** Con el tiempo, las criaturas pueden evolucionar (¡incluso a estado zombie!) o, si su vida llega a cero, despedirse del Valle.
* **🖥️ Mira el Mapa:** Verás una representación sencilla del mapa en tu pantalla, para que sepas dónde está cada tipo de terreno.

### 🎮 ¿Cómo se juega? (Paso a paso):

Es muy fácil ser el espectador de este mundo:

1.  **Inicia la Aventura:** Abre el juego (el archivo `.exe`).
2.  **Elige el Escenario:**
    * Te preguntará qué bioma prefieres:
        ```
        Selecciona el bioma:
        1. Boscoso - Terrenos Densos, Claros y Oscuros
        2. Volcanico - Terrenos Rocosos, Senizas y Fumarolas
        Ingresa la opcion:
        ```
    * Escribe `1` o `2` y presiona `Enter`.
3.  **¡Comienza la Magia!** Verás el tamaño del mapa y cuántas criaturas empezaron la aventura. También aparecerá el primer vistazo del mapa.
4.  **Controla el Tiempo:**
    * Después de cada turno, el mapa se actualizará, y te preguntará qué hacer:
        ```
        Escriba un comando o (s) para continuar.
        ```
    * Pulsa `s` y `Enter`➡️ para pasar al siguiente turno y ver qué pasa.
    * Pulsa `t` y `Enter`🔢 para saber cuántas criaturas siguen vivas.
    * Pulsa `e` y `Enter`🚪 para cerrar el juego y volver a la realidad.
5.  **El Fin (o un Nuevo Comienzo):** La simulación se detiene si todas las criaturas han perecido o si tú decides salir.

### ✅ Requisitos (Lo que necesitas):

* **Sistema Operativo:** Solo para **Windows** 윈도우 🖥️ (usamos algunas cositas específicas de este sistema).
* **Para los curiosos que compilan:** Un compilador de C++ que entienda C++11 (como MinGW g++).
* **Consola Bonita:** Que tu consola muestre bien los caracteres especiales (el juego intenta ayudar con esto).

## 🚀 ¡A Jugar! (Instalación y Ejecución) 🎉

Tienes dos caminos para adentrarte en el Valle:

### Opción 1: ¡Lo Más Fácil! (Descargar el .EXE para Windows) 👍✨

1.  Ve a la sección de **"Releases"** de nuestro repositorio en GitHub:
    [https://github.com/Jdmesa/Las-cicatrices_Cpp/releases](https://github.com/Jdmesa/Las-cicatrices_Cpp/releases)
2.  Descarga el archivo `.exe` más reciente.
3.  ¡Ejecútalo y listo! Recuerda, **SOLO FUNCIONA EN WINDOWS**.

### Opción 2: Para los Valientes (Compilar el Código Fuente) 💻🔥

Si te gusta ver cómo están hechas las cosas y quieres compilarlo tú mismo:

1.  **Clona el Tesoro (Código Fuente):**
    Necesitarás Git instalado. Abre una terminal y escribe:
    ```bash
    git clone https://github.com/Jdmesa/Las-cicatrices_Cpp.git
    ```
    Luego, entra a la carpeta que se creó:
    ```bash
    cd Las-cicatrices_Cpp
    ```
2.  **Prepara tus Herramientas:** Asegúrate de tener un compilador de C++ (como g++ de MinGW en Windows) que sepa de C++11.
3.  **¡A Compilar!**
    En la terminal, dentro de la carpeta del proyecto, escribe este comando mágico (puede parecer largo, ¡pero funciona!):
    ```bash
    g++ -std=c++11 main.cpp Ecosistema/*.cpp Criaturas/*.cpp Atributos/*.cpp -o LasCicatricesDelValle.exe
    ```
    Esto tomará todos los pedacitos de código y los unirá en un solo programa ejecutable llamado `LasCicatricesDelValle.exe`.
4.  **¡Ejecuta tu Creación!**
    Escribe en la terminal:
    ```bash
    ./LasCicatricesDelValle.exe
    ```
    O simplemente:
    ```bash
    LasCicatricesDelValle.exe
    ```

## 🛠️ Así está hecho el Valle (Un vistazo al Código) ⚙️

Para los que sienten curiosidad por las tuercas y tornillos del proyecto, aquí un pequeño mapa de cómo está organizado el código:

* **Raíz del Proyecto (`/`)**:
    * `main.cpp`: ¡Aquí empieza todo! Es el que te da la bienvenida y pone en marcha el ecosistema.

* **`Atributos/`**: Aquí viven las "habilidades especiales" y el molde base de las criaturas.
    * `criatura.h/.cpp`: Es como el ADN base de todas las criaturas. Define qué pueden hacer (moverse, pelear, etc.) y qué tienen (vida, posición).
    * `fantasma.h/.cpp`: El truco para ser etéreo y recibir menos daño.
    * `regeneracion.h/.cpp`: La habilidad de curarse las heridas.
    * `volador.h/.cpp`: ¡Las alas para surcar los cielos del mapa!

* **`Criaturas/`**: ¡El bestiario! Cada tipo de criatura tiene sus propios archivos aquí.
    * `dragon.h/.cpp`, `enano.h/.cpp`, `hada.h/.cpp`, `gigante.h/.cpp`: Son los planos detallados de cada ser, diciendo exactamente cómo se comportan y qué atributos especiales tienen.

* **`Ecosistema/`**: Las reglas del mundo y cómo funciona todo junto.
    * `ecosistema.h/.cpp`: El director de orquesta. Controla los turnos, crea las criaturas y se comunica contigo.
    * `mapa.h/.cpp`: El tablero de juego. Sabe cómo es el terreno y dónde está cada cosa.
    * `nodo.h/.cpp`: Cada cuadradito del mapa. Sabe qué tipo de terreno es y qué criaturas hay en él. ¡Aquí ocurren las peleas!

Resumidamente, usamos la Programación Orientada a Objetos para que cada parte del juego (criaturas, mapa, habilidades) como una pieza de Lego que podemos combinar y modificar.

---
*README fue creado con la ayuda de la IA y la información proporcionada por los valientes desarrolladores. (merecemos un 5.0) :)*