#pragma once

#include <glad/glad.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"


// instrinsic to compiler: the __ lets use know that its intrinsic to msvc. Apparently only sort of
#define ASSERT(x) if (!(x)) __debugbreak();

// the "\" lets us ignore the newline character, allowing us to break this into multiple lines for readability
    // note, do not put a " " space after the "\" or the newline character will still be there as its the " " getting ignored
// the "#" turns whatever "x" is into a string
// the "__" here is not an intrinsic, should be supported by all compilers
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__)) 


void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);

class Renderer
{
private:

public:
    void Clear() const;
    void Draw(const VertexArray& a, const IndexBuffer& ib, const Shader& shader) const;



};
