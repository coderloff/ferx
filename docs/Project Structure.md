# Project Structure

There are four main folders in the project: `editor`, `engine`, `thirdparty`, and `docs`

- **Engine**: classes for the core engine
  - `Engine`: main engine class handling instances
  - `FrameBuffer`, `IndexBuffer`, `VertexBuffer`, `VertexArray`: class implementations of buffers and vertex array
  - `Shader`, `Texture` - class implementations handling shaders and textures
  - `Input`: input handling using GLFW
  - `Window`: window management using GLFW
  - `Renderer`: basic renderings and overall handlings
  - `UI`: user interface handling using ImGui
  - `Camera`: basic camera implementation supporting movement and rotation

- **Editor**: main executable to interact with the engine
  - `Resources`: folder containing fonts, shaders, and assets
  - `Editor`: main editor class handling 
  - `Main`: executing arguments and configurations

- **Thirdparty**: different external libraries like GLFW or ImGui
  - `GLAD`: extension loader for modern OpenGL functions
  - `GLFW`: multi-platform library for window and input handling
  - `GLM`: mathematics library for complex computations
  - `ImGui`: graphical user interface for C++
  - `stb_image`: single-header file for handling image loading

- **Docs**: documentations to understand overall process