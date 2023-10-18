#include <memory>
#include "AVL.h"
#include <queue>
#include <stack>

using namespace avl;

AVL::AVL() : _screen_render{}, _geometry{}, _timeScale{}, _inputManager{} { }

AVL::~AVL() { }

void AVL::Render(uint32_t width, uint32_t height, uint32_t bitsPerPixel)
{
	_screen_render.Render(width, height, bitsPerPixel);
}

Vector2u AVL::GetSize()
{
	return _screen_render.GetSize();
}

void AVL::Start(bool showFps)
{
    sf::Clock globalDeltaTimeClock;
    sf::Clock frameClock;
    sf::Clock frameCalcClock;

    _timeScale.InitFrameRateController();
    OnUserStart();

    // run the program as long as the window is open
    while (_screen_render._window->isOpen())
    {
        _timeScale.SetDeltaTime(globalDeltaTimeClock);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (_screen_render._window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                _screen_render._window->close();
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

        _screen_render.Display();

        sf::sleep(_timeScale.frameTime - _timeScale.elapsedTime);
    }
}

void AVL::OnUserStart() {}

void AVL::OnUserUpdate() {}

void AVL::Clear(const sf::Color& color)
{
    _screen_render.Clear(color);
}

void AVL::Display()
{
    _screen_render.Display();
}

void AVL::Draw(int32_t x, int32_t y, const sf::Color& color) 
{ 
    _geometry.Draw(x, y, _screen_render._window, color); 
}

void AVL::Draw(const sf::Vector2i& pos, const sf::Color& color) 
{
    _geometry.Draw(pos.x, pos.y, _screen_render._window, color);
}

void AVL::DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const sf::Color& color) 
{ 
    _geometry.DrawLine(x1, y1, x2, y2, _screen_render._window, color); 
}

void AVL::DrawLine(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Color& color) 
{
    _geometry.DrawLine(pos1.x, pos1.y, pos2.x, pos2.y, _screen_render._window, color);
}

void AVL::DrawCircle(int32_t x, int32_t y, int32_t radius, const sf::Color& color) 
{ 
    _geometry.DrawCircle(x, y, radius, _screen_render._window, color); 
}

void AVL::DrawCircle(const sf::Vector2i& pos, int32_t radius, const sf::Color& color) 
{
    _geometry.DrawCircle(pos.x, pos.y, radius, _screen_render._window, color);
}

void AVL::FillCircle(int32_t x, int32_t y, int32_t radius, const sf::Color& color) 
{ 
    _geometry.FillCircle(x, y, radius, _screen_render._window, color); 
}

void AVL::FillCircle(const sf::Vector2i& pos, int32_t radius, const sf::Color& color) 
{
    _geometry.FillCircle(pos.x, pos.y, radius, _screen_render._window, color);
}

void AVL::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, const sf::Color& color) 
{ 
    _geometry.DrawRect(x, y, w, h, _screen_render._window, color); 
}

void AVL::DrawRect(const sf::Vector2i& pos, int32_t w, int32_t h, const sf::Color& color) 
{
    _geometry.DrawRect(pos.x, pos.y, w, h, _screen_render._window, color);
}

void AVL::FillRect(int32_t x, int32_t y, int32_t w, int32_t h, const sf::Color& color) 
{ 
    _geometry.FillRect(x, y, w, h, _screen_render._window, color); 
}

void AVL::FillRect(const sf::Vector2i& pos, int32_t w, int32_t h, const sf::Color& color) 
{
    _geometry.FillRect(pos.x, pos.y, w, h, _screen_render._window, color);
}

void AVL::DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, const sf::Color& color) 
{ 
    _geometry.DrawTriangle(x1, y1, x2, y2, x3, y3, _screen_render._window, color); 
}

void AVL::DrawTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, const sf::Color& color) 
{
    _geometry.DrawTriangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, _screen_render._window, color);
}

void AVL::FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, const sf::Color& color) 
{ 
    _geometry.FillTriangle(x1, y1, x2, y2, x3, y3, _screen_render._window, color); 
}

void AVL::FillTriangle(const sf::Vector2i& pos1, const sf::Vector2i& pos2, const sf::Vector2i& pos3, const sf::Color& color) 
{
    _geometry.FillTriangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, _screen_render._window, color);
}

void AVL::DrawString(int32_t x1, int32_t y1, const std::string& text, const std::string& font, const sf::Color& color, uint32_t scale)
{
    _geometry.DrawString(x1, y1, text, font, _screen_render._window, color, scale);
}

void AVL::DrawString(const sf::Vector2i& pos, const std::string& text, const std::string& font, const sf::Color& color, uint32_t scale) 
{
    _geometry.DrawString(pos.x, pos.y, text, font, _screen_render._window, color, scale);
}

void AVL::DrawLine(float x1, float y1, float x2, float y2)
{
    _geometry.DrawLine(x1, y1, x2, y2, _screen_render._window);
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

void AVL::DrawTree(PointerGridNode* root, Grid _grid)
{
    int height = CalculateTreeHeight(root);
    int row = 0, column = _grid.GetCenterColumn();

    CalculateNodeGridPosition(root, row, column - 1, height);
    DrawGridTreeLines(root, _grid);
    DrawGridTreeNodes(root, _grid);

    Display();
}

void AVL::DrawTree(const std::vector<int>& nodes, Grid _grid) 
{
    if (nodes.size() == 0) {
        return;
    }

    PointerGridNode* root = ConvertToNodes(nodes);

    int height = CalculateTreeHeight(root);
    int row = 0, column = _grid.GetCenterColumn();

    CalculateNodeGridPosition(root, row, column - 1, height);
    DrawGridTreeLines(root, _grid);
    DrawGridTreeNodes(root, _grid);

    Display();
}

void AVL::DrawTreeLines(PointerNode* root, float x, float y, float horizontalSpacingLeft, float horizontalSpacingRight)
{
    if (root == nullptr) {
        return;
    }

    if (root->left != nullptr) {

        DrawLine(x, y, x - horizontalSpacingLeft, y + 100);
        DrawTreeLines(root->left, x - horizontalSpacingLeft, y + 100, horizontalSpacingLeft, horizontalSpacingRight);
    }

    if (root->right != nullptr) {

        DrawLine(x, y, x + horizontalSpacingRight, y + 100);
        DrawTreeLines(root->right, x + horizontalSpacingRight, y + 100, horizontalSpacingLeft, horizontalSpacingRight);
    }
}

void AVL::DrawTreeNodes(PointerNode* root, float x, float y, float horizontalSpacingLeft, float horizontalSpacingRight)
{
    if (root == nullptr) {
        return;
    }

    int circleRadius = 20;
    float circleX = x - circleRadius;
    float circleY = y - circleRadius;

    FillCircle(circleX, circleY, circleRadius, avl::WHITE);
    DrawString(x - 8, y - 10, std::to_string(root->data), avl::ARIAL, avl::RED, 20);

    if (root->left != nullptr) {

        DrawTreeNodes(root->left, x - horizontalSpacingLeft, y + 100, horizontalSpacingLeft, horizontalSpacingRight);
    }

    if (root->right != nullptr) {

        DrawTreeNodes(root->right, x + horizontalSpacingRight, y + 100, horizontalSpacingLeft, horizontalSpacingRight);
    }
}

void AVL::DrawGridTreeLines(PointerGridNode* root, Grid _grid)
{
    if (root == nullptr) {
        return;
    }

    auto _coordinates =
        _grid.SetItemPositionAnchor(_grid.GetColumnPosition(root->column),
            _grid.GetLinePosition(root->row));

    if (root->left != nullptr) {

        auto _nextCoordinates =
            _grid.SetItemPositionAnchor(_grid.GetColumnPosition(root->left->column),
                _grid.GetLinePosition(root->left->row));

        DrawLine(_coordinates.GetX(), _coordinates.GetY(), _nextCoordinates.GetX(), _nextCoordinates.GetY());
        DrawGridTreeLines(root->left, _grid);
    }

    if (root->right != nullptr) {

        auto _nextCoordinates =
            _grid.SetItemPositionAnchor(_grid.GetColumnPosition(root->right->column),
                _grid.GetLinePosition(root->right->row));

        DrawLine(_coordinates.GetX(), _coordinates.GetY(), _nextCoordinates.GetX(), _nextCoordinates.GetY());
        DrawGridTreeLines(root->right, _grid);
    }
}

void AVL::DrawGridTreeNodes(PointerGridNode* root, Grid _grid)
{
    if (root == nullptr) {
        return;
    }

    int radius = 20;
    auto _coordinates = _grid.CalculateGridCircleCoordinates(radius, root->row, root->column);
    FillCircle(_coordinates.GetX(), _coordinates.GetY(), radius, avl::WHITE);

    int scale = 20;
    _coordinates = _grid.CalculateGridTextCoordinates(scale, root->row, root->column);
    DrawString(_coordinates.GetX(), _coordinates.GetY(), std::to_string(root->data), avl::ARIAL, avl::RED, scale);

    if (root->left != nullptr) {

        DrawGridTreeNodes(root->left, _grid);
    }

    if (root->right != nullptr) {

        DrawGridTreeNodes(root->right, _grid);
    }
}

int AVL::CalculateTreeHeight(PointerGridNode* root) 
{
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = CalculateTreeHeight(root->left);
    int rightHeight = CalculateTreeHeight(root->right);
    return 1 + std::max(leftHeight, rightHeight);
}

void AVL::CalculateNodeGridPosition(PointerGridNode* root, int row, int column, int treeHeight)
{
    if (root == nullptr) {
        return;
    }

    int columnsGap = treeHeight / (row + 1);

    root->row = row;
    root->column = column;

    if (root->left != nullptr) {

        CalculateNodeGridPosition(root->left, row + 1, column - columnsGap, treeHeight);
    }

    if (root->right != nullptr) {

        CalculateNodeGridPosition(root->right, row + 1, column + columnsGap, treeHeight);
    }
}

Utils::PointerGridNode* AVL::ConvertToNodes(const std::vector<int>& nodes, int index)
{
    std::vector<PointerGridNode*> createdNodes;
    for (int i = 0; i < nodes.size(); i++) {

        if (nodes[i] == NULL) {
            createdNodes.push_back(NULL);
        }
        else {
            createdNodes.push_back(CreatePointerGridNode(nodes[i]));
        }
    }

    PointerGridNode* root = createdNodes[0];

    for (int i = 0; i < createdNodes.size(); i++) {

        if (createdNodes[i] == NULL) {
            continue;
        }

        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < createdNodes.size()) {
            if (createdNodes[leftChild] != NULL) {
                createdNodes[i]->left = createdNodes[leftChild];
            }
        }

        if (rightChild < createdNodes.size()) {
            if (createdNodes[rightChild] != NULL) {
                createdNodes[i]->right = createdNodes[rightChild];
            }
        }
    }

    return root;
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
        DrawString(x + circleRadius / 2, y + circleRadius / 2, std::to_string(nodes[i].value), avl::ARIAL, avl::RED, 20);
    }

    Display();
}

Grid AVL::CreateGrid(int screenWidth, int screenHeight, GridItemAnchor _itemAnchor, int itemSize)
{
    return { screenWidth, screenHeight, _itemAnchor, itemSize };
}

void AVL::ViewGrid(Grid _grid, bool showAnchor, bool viewText)
{
    auto items = _grid.GetItems();
    int itemSize = _grid.GetItemSize();

    for (int i = 0; i < items.size(); i++)
    {
        auto& item = items.at(i);

        if (viewText)
        {
            std::cout << "[" << i << "]" << "X: " << item.positionX << " Y: " << item.positionY << std::endl;
        }
        else
        {
            _geometry.DrawRect(item.positionX, item.positionY, itemSize, itemSize, _screen_render._window, avl::CYAN);

            if (showAnchor) 
            {
                int radius = 20;
                float circleX = item.positionX - radius;
                float circleY = item.positionY - radius;

                Coordinates coordinates =
                    _grid.SetItemPositionAnchor(circleX, circleY);

                _geometry.FillCircle(coordinates.GetX(), coordinates.GetY(), 20, _screen_render._window, avl::RED);
            }
        }
    }
}