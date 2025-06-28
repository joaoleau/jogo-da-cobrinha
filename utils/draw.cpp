#include <GLFW/glfw3.h>
#define STB_EASY_FONT_IMPLEMENTATION
#include "../include/utils/stb_easy_font.h"
#include "../include/utils/draw_utils.h"

void drawText(float x, float y, const char* text) {
    char buffer[99999];
    int quads = stb_easy_font_print(x, y, (char*)text, NULL, buffer, sizeof(buffer));

    glColor3f(1.0f, 1.0f, 1.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 16, buffer);
    glDrawArrays(GL_QUADS, 0, quads * 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void drawBackground(int gridWidth, int gridHeight) {
    float cellWidth = 2.0f / gridWidth;
    float cellHeight = 2.0f / gridHeight;

    for (int y = 0; y < gridHeight; ++y) {
        for (int x = 0; x < gridWidth; ++x) {
            bool dark = (x + y) % 2 == 0;
            if (dark)
                glColor3f(0.2f, 0.2f, 0.2f);
            else
                glColor3f(0.3f, 0.3f, 0.3f);

            float px = x * cellWidth - 1.0f;
            float py = y * cellHeight - 1.0f;

            glBegin(GL_QUADS);
            glVertex2f(px, py);
            glVertex2f(px + cellWidth, py);
            glVertex2f(px + cellWidth, py + cellHeight);
            glVertex2f(px, py + cellHeight);
            glEnd();
        }
    }
}
