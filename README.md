# João Vitor Leal - SP3122972 | IFSP BSI Computação Gráfica 5 Semestre
# 🐍 Cobrinha

Um jogo simples da cobrinha feito em C++ com OpenGL e GLFW.  
Controle a cobrinha com as setas do teclado e colete a comida para aumentar sua pontuação.  
O jogo reinicia automaticamente ao colidir com a parede ou com o próprio corpo.

---

## 🎮 Controles

- **Setas (↑ ↓ ← →)** — Movimentam a cobrinha  
- **Espaço** — Inicia ou reinicia o jogo

---

## 🛠️ Requisitos

Antes de compilar, certifique-se de ter:

- [CMake ≥ 3.10](https://cmake.org/)
- [MinGW](http://www.mingw.org/) instalado e no PATH (`mingw32-make`)
- GLFW baixado e extraído em:  
  `C:/libs/glfw/`  
  Com os seguintes subdiretórios:
  - `C:/libs/glfw/include/` — cabeçalhos (`GLFW/glfw3.h`)
  - `C:/libs/glfw/lib/` — bibliotecas (`glfw3.lib`, etc.)

---

## 🧱 Como compilar com CMake + MinGW

   ```bash
   mkdir build
   cd build
   cmake -G "MinGW Makefiles" ..
   mingw32-make
