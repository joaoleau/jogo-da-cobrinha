# João Vitor Leal - SP3122972 | IFSP BSI Computação Gráfica 5º Semestre  
# 🐍 Cobrinha

Um jogo simples da cobrinha feito em C++ usando OpenGL e FreeGLUT.  
Controle a cobrinha com as setas do teclado e colete a comida para aumentar sua pontuação.  
O jogo reinicia automaticamente ao colidir com a parede ou com o próprio corpo.

---

## 🎮 Controles

- **Setas (↑ ↓ ← →)** — Movimentam a cobrinha  
- **Espaço** — Inicia ou reinicia o jogo  
- **ESC** — Sai do jogo

---

## 🛠️ Requisitos

Antes de compilar, certifique-se de ter:

- [MinGW](http://www.mingw.org/) instalado e disponível no PATH  
- FreeGLUT instalado, com:  
  - Headers em `C:/ProgramData/mingw64/mingw64/include/GL/`  
  - Libs em `C:/ProgramData/mingw64/mingw64/lib/`  
  - DLL `freeglut.dll` disponível na pasta do executável ou no PATH do Windows

---

## 🧱 Como compilar

Abra o terminal no diretório raiz do projeto e rode:

```bash
g++ src/main.cpp src/snake.cpp src/food.cpp utils/draw_utils.cpp utils/keycallback.cpp \
 -o cobrinha.exe \
 -Iinclude -IC:/ProgramData/mingw64/mingw64/include \
 -LC:/ProgramData/mingw64/mingw64/lib \
 -lfreeglut -lopengl32 -lglu32
