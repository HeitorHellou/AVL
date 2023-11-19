
#include "AVL.h"

using namespace avl;

AVL::AVL() : _screen_renderer{}, _geometry{}, _timeScale{}, _inputManager{}, _grid{} { }

AVL::~AVL() { }

void AVL::Renderer(uint32_t width, uint32_t height, uint32_t bitsPerPixel)
{
	_screen_renderer.Renderer(width, height, bitsPerPixel);
}

Vector2u AVL::GetSize()
{
	return _screen_renderer.GetSize();
}

void AVL::Start(bool showFps)
{
    sf::Clock globalDeltaTimeClock;
    sf::Clock frameClock;
    sf::Clock frameCalcClock;

    _timeScale.InitFrameRateController();
    OnUserStart();

    // run the program as long as the window is open
    while (_screen_renderer._window->isOpen())
    {
        _timeScale.SetDeltaTime(globalDeltaTimeClock);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (_screen_renderer._window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                _screen_renderer._window->close();
            else if (event.type == sf::Event::MouseWheelScrolled)
                _inputManager.UpdateMouseWheelDelta(event);
        }

        _timeScale.elapsedTime += frameCalcClock.restart();

        // Lock frame rate
        while (_timeScale.elapsedTime >= _timeScale.frameTime)
        {
            OnUserUpdate();

            _timeScale.frameCount++;
            if (showFps)
            {
                if (frameClock.getElapsedTime().asSeconds() >= 1.0f) {
                    float fps = _timeScale.frameCount / frameClock.getElapsedTime().asSeconds();
                    std::cout << "FPS: " << fps << std::endl;

                    _timeScale.frameCount = 0;
                    frameClock.restart();
                }
            }
            _timeScale.elapsedTime -= _timeScale.frameTime;
        }

        _screen_renderer.Display();

        avl::TimeScale::Wait(_timeScale.frameTime - _timeScale.elapsedTime);
    }
}

void AVL::OnUserStart() {}

void AVL::OnUserUpdate() {}

void AVL::Clear(const sf::Color& color)
{
    _screen_renderer.Clear(color);
}

void AVL::Display()
{
    _screen_renderer.Display();
}

void AVL::Draw(int32_t x, int32_t y, const sf::Color& color) 
{ 
    _geometry.Draw(x, y, _screen_renderer._window, color); 
}

void AVL::Draw(const sf::Vector2i& pos, const sf::Color& color) 
{
    _geometry.Draw(pos.x, pos.y, _screen_renderer._window, color);
}

void AVL::DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const sf::Color& color) 
{ 
    _geometry.DrawLine(x1, y1, x2, y2, _screen_renderer._window, color); 
}

void AVL::DrawLine(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Color& color) 
{
    _geometry.DrawLine(pos1.x, pos1.y, pos2.x, pos2.y, _screen_renderer._window, color);
}

void AVL::DrawCircle(int32_t x, int32_t y, int32_t radius, const sf::Color& color) 
{ 
    _geometry.DrawCircle(x, y, radius, _screen_renderer._window, color); 
}

void AVL::DrawCircle(const sf::Vector2i& pos, int32_t radius, const sf::Color& color) 
{
    _geometry.DrawCircle(pos.x, pos.y, radius, _screen_renderer._window, color);
}

void AVL::FillCircle(int32_t x, int32_t y, int32_t radius, const sf::Color& color) 
{ 
    _geometry.FillCircle(x, y, radius, _screen_renderer._window, color); 
}

void AVL::FillCircle(const sf::Vector2i& pos, int32_t radius, const sf::Color& color) 
{
    _geometry.FillCircle(pos.x, pos.y, radius, _screen_renderer._window, color);
}

void AVL::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, const sf::Color& color) 
{ 
    _geometry.DrawRect(x, y, w, h, _screen_renderer._window, color); 
}

void AVL::DrawRect(const sf::Vector2i& pos, int32_t w, int32_t h, const sf::Color& color) 
{
    _geometry.DrawRect(pos.x, pos.y, w, h, _screen_renderer._window, color);
}

void AVL::FillRect(int32_t x, int32_t y, int32_t w, int32_t h, const sf::Color& color) 
{ 
    _geometry.FillRect(x, y, w, h, _screen_renderer._window, color); 
}

void AVL::FillRect(const sf::Vector2i& pos, int32_t w, int32_t h, const sf::Color& color) 
{
    _geometry.FillRect(pos.x, pos.y, w, h, _screen_renderer._window, color);
}

void AVL::DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, const sf::Color& color) 
{ 
    _geometry.DrawTriangle(x1, y1, x2, y2, x3, y3, _screen_renderer._window, color); 
}

void AVL::DrawTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, const sf::Color& color) 
{
    _geometry.DrawTriangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, _screen_renderer._window, color);
}

void AVL::FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, const sf::Color& color) 
{ 
    _geometry.FillTriangle(x1, y1, x2, y2, x3, y3, _screen_renderer._window, color); 
}

void AVL::FillTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, const sf::Color& color) 
{
    _geometry.FillTriangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, _screen_renderer._window, color);
}

void AVL::DrawString(int32_t x1, int32_t y1, const std::string& text, const std::string& font, const sf::Color& color, uint32_t scale)
{
    _geometry.DrawString(x1, y1, text, font, _screen_renderer._window, color, scale);
}

void AVL::DrawString(const sf::Vector2i& pos, const std::string& text, const std::string& font, const sf::Color& color, uint32_t scale) 
{
    _geometry.DrawString(pos.x, pos.y, text, font, _screen_renderer._window, color, scale);
}

void AVL::DrawLine(float x1, float y1, float x2, float y2)
{
    _geometry.DrawLine(x1, y1, x2, y2, _screen_renderer._window);
}

sf::Time AVL::GetDeltaTime()
{
    return _timeScale.GetDeltaTime();
}

float AVL::GetDeltaTimeAsSeconds() 
{
    return _timeScale.GetDeltaTimeAsSeconds();
}

void AVL::SetFrameRate(float targetFramerate) 
{
    _timeScale.SetFrameRate(targetFramerate);
}

void AVL::DrawQueue(const std::queue<int>& q)
{
    Clear(avl::BLACK);

    int queueSize = q.size();
    int squareSize = 50;
    float scaleFactor = static_cast<float>(600 - 2) / static_cast<float>(queueSize);
    int midScreen = (q.size() * (squareSize + 10)) / 2;

    int x = 400 - squareSize / 2;
    int y = 300 - midScreen;

    std::queue<int> tempQueue = q;

    for (int k = 0; !tempQueue.empty(); ++k)
    {
        int frontValue = tempQueue.front();
        tempQueue.pop();

        sf::Color squareColor = avl::BLUE;
        if (k == queueSize) {
            sf::Color squareColor = avl::RED;
        }

        FillRect(x - squareSize / 2, y - squareSize / 2, squareSize, squareSize, squareColor);

        DrawString(x, y, std::to_string(frontValue), avl::ARIAL, avl::WHITE, 20);

        y += squareSize + 10;

    }

    Display();
}

void AVL::DrawStack(const std::stack<int>& s)
{
    Clear(avl::BLACK);

    int stackSize = s.size();
    int squareSize = 50;
    int midScreen = (s.size() * (squareSize + 10)) / 2;

    int x = 400 - squareSize / 2;
    int y = 300 - midScreen;

    std::stack<int> tempStack = s;

    for (int k = 0; !tempStack.empty(); ++k)
    {
        int frontValue = tempStack.top();
        tempStack.pop();

        sf::Color squareColor = avl::BLUE;
        if (k == 0) {
            sf::Color squareColor = avl::RED;
        }

        FillRect(x - squareSize / 2, y - squareSize / 2, squareSize, squareSize, squareColor);

        DrawString(x, y, std::to_string(frontValue), avl::ARIAL, avl::WHITE, 20);

        y += squareSize + 10;

    }

    Display();

}

void AVL::DrawArray(std::vector<int>& arr)
{
    Vector2u dimensions = GetSize();
    auto screenWidth = dimensions._x;
    auto screenHeight = dimensions._y;
    int margin = 10;
    int spacing = 2;

    int maxElement = *std::max_element(arr.begin(), arr.end());
    int barWidth = (screenWidth - 2 * margin - (arr.size() - 1) * spacing) / arr.size();
    float scaleFactor = static_cast<float>(screenHeight - 2 * margin) / static_cast<float>(maxElement);

    for (size_t k = 0; k < arr.size(); ++k)
    {
        int barHeight = static_cast<int>(arr[k] * scaleFactor);
        int x = margin + k * (barWidth + spacing);
        int y = screenHeight - margin - barHeight;

        sf::Color barColor = avl::WHITE;

        FillRect(x, y, barWidth, barHeight, barColor);
    }
    Display();

    avl::TimeScale::Wait(1000);
}

void AVL::DrawTree(const std::shared_ptr<TreeNode>& root, int row, int col, int startRow, int startCol)
{
    if (root == nullptr) {
        return;
    }

    int middleCol = std::floor((startCol + col) / 2);
    int x = middleCol * _grid.getCellWidth();
    int y = startRow * _grid.getCellHeight();
    int data = root->data;

    int radius = 20;

    if (root->left != nullptr)
    {
        int leftX = std::floor((0 + middleCol) / 2) * _grid.getCellWidth();
        int leftY = (startRow + 1) * _grid.getCellHeight();
        DrawLine(x + radius, y + radius, leftX + radius, leftY + radius);
    }

    if (root->right != nullptr)
    {
        int leftX = std::floor(((middleCol + 1) + col) / 2) * _grid.getCellWidth();
        int leftY = (startRow + 1) * _grid.getCellHeight();
        DrawLine(x + radius, y + radius, leftX + radius, leftY + radius);
    }

    DrawTreeNode(x, y, data, radius);

    DrawTree(root->left, row, middleCol, startRow + 1, 0);
    DrawTree(root->right, row, col, startRow + 1, middleCol + 1);
}

void AVL::DrawTreeNode(int x, int y, int data, int radius)
{
    FillCircle(x, y, radius, avl::WHITE);
    DrawString(x + (radius / 2), y + (radius / 2), std::to_string(data), avl::ARIAL, avl::RED, 20);
}

void AVL::DrawGraph(const std::vector<Node>& nodes, const std::vector<Edge>& edges) 
{
    Clear(avl::BLACK);

    // Draw edges
    for (const auto& edge : edges)
    {
        float startX = nodes[edge.startNode].x;
        float startY = nodes[edge.startNode].y;
        float endX = nodes[edge.endNode].x;
        float endY = nodes[edge.endNode].y;
        DrawLine(startX, startY, endX, endY, avl::WHITE);
    }

    // Draw nodes
    float circleRadius = 20.0f;
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        float x = nodes[i].x - circleRadius;
        float y = nodes[i].y - circleRadius;
        FillCircle(x, y, circleRadius, avl::WHITE);

        // Draw the value inside the circle
        DrawString(x + circleRadius / 2, y + circleRadius / 2, std::to_string(i), avl::ARIAL, avl::RED, 20);
    }

    Display();
}

void AVL::CreateGrid(int row, int col)
{
    _grid.setGrid(_screen_renderer._width, _screen_renderer._height, row, col);
}

void AVL::CreateGrid(int treeHeight)
{
    _grid.setGrid(_screen_renderer._width, _screen_renderer._height, treeHeight);
}