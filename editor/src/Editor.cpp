#include "Editor.h"

Editor::Editor()= default;

Editor::~Editor()
{
    Shutdown();
}

void Editor::Init()
{
    auto engine = Engine();

    engine.Run();
}

void Editor::Run() {
}

void Editor::Shutdown() {

}