#include <raylib.h>
#include <iostream>
#include <string>
#include "login.h"
#include <vector>
using namespace std;
Rectangle balanceRec { 100, 350, 800, 500 };
Rectangle assetRec{ 1000, 200, 800, 800 };
bool isSelectedExitBtn, isSelectedManageBtn, isSelectedWalletBtn, isSelectedAddBtn, isSelectedLiabBtn, isSelectedAssetBtn, isSelectedAddCash, isSelectedTriangleTop, isSelectedTriangleBottom;
int assetCounter;
bool isClickedLiabilities, isClickedAssets, isUpdatedAssets, isUpdatedLiabilities;
vector <string> assets = {"My Asset #1", "My Asset #2", "My Asset #3", "My Asset #4", "My Asset #5", "My Asset #6"};
vector <string> liabilities = { "My Liability #1", "My Liability #2", "My Liability #3", "My Liability #4", "My Liability #5", "My Liability #6" };
vector <string> currentShown = assets;
	
void WalletMenu(float currentBalance, int fontSize, Font font, Texture2D triangle)
{
	Color c1, c2, c3, c4, c5, c6, c7;
	if (isSelectedWalletBtn) c1 = LIGHTGRAY; else c1 = RAYWHITE;
	if (isSelectedManageBtn) c2 = LIGHTGRAY; else c2 = RAYWHITE;
	if (isSelectedExitBtn) c3 = LIGHTGRAY; else c3 = RAYWHITE;
	if (isSelectedAddCash) c4 = LIGHTGRAY; else c4 = RAYWHITE;
	if (isSelectedAssetBtn) c5 = LIGHTGRAY; else c5 = RAYWHITE;
	if (isSelectedLiabBtn) c6 = LIGHTGRAY; else c6 = RAYWHITE;
	if (isSelectedAddBtn) c7 = LIGHTGRAY; else c7 = RAYWHITE;
	if (isSelectedLiabBtn && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		currentShown = liabilities;
		isClickedLiabilities = true;
		isClickedAssets - false;
	}
	if (isSelectedAssetBtn && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		currentShown = assets;
		isClickedLiabilities = false;
		isClickedAssets = true;
	}
	BeginDrawing();
	ClearBackground(LIGHTGRAY);
	DrawRectangle(0, 0, 1920, 120, DARKBLUE);
	DrawTextEx(font, TextFormat("Hello, %s", loggedUsername.c_str()), Vector2{ 150, 200 }, 100, 10, BLACK);
	DrawRectangleRounded(balanceRec, 0.2, 0, WHITE); //balance rectangle
	DrawRectangleRoundedLines(balanceRec, 0.2, 0, 5, BLACK); // balance rectangle lines
	DrawTextEx(font, "MyWill Balance", Vector2{ 270, 400 }, 80, 1, BLACK);
	DrawTextEx(font, TextFormat("%.2f EUR", currentBalance), Vector2{ 120,560 }, fontSize, 10, BLACK);
	DrawRectangleRounded(assetRec, 0.2, 0, WHITE); // asset rectangle
	DrawRectangleRoundedLines(assetRec, 0.2, 0, 5, BLACK); // asset rectangle line
	DrawRectangleRounded({ 1050, 210, 280,80 }, 0.2, 0, c5);
	DrawRectangleRoundedLines({ 1050, 210, 280,80 }, 0.2, 0,5, BLACK);
	DrawRectangleRounded({ 1470, 210, 280,80 }, 0.2, 0, c6);
	DrawRectangleRoundedLines({ 1470, 210, 280,80 }, 0.2, 0, 5, BLACK);
	DrawRectangleRounded({ 1250, 910, 280,80 }, 0.2, 0, c7);
	DrawRectangleRoundedLines({ 1250, 910, 280,80 }, 0.2, 0, 5, BLACK);
	DrawRectangleRounded({20, 30, 280,80 }, 0.2, 0, c1);
	DrawRectangleRoundedLines({ 20, 30, 280,80 }, 0.2, 0, 5, BLACK);
	DrawRectangleRounded({ 350, 30, 280,80 }, 0.2, 0, c2);
	DrawRectangleRoundedLines({ 350, 30, 280,80 }, 0.2, 0, 5, BLACK);
	DrawRectangleRounded({ 1600, 30, 280,80 }, 0.2, 0, c3);
	DrawRectangleRoundedLines({ 1600, 30, 280,80 }, 0.2, 0, 5, BLACK);
	DrawRectangleRounded({ 350, 760, 280,80 }, 0.2, 0, c4);
	DrawRectangleRoundedLines({ 350, 760, 280,80 }, 0.2, 0, 5, BLACK);
	DrawTextEx(font, "Logout", Vector2{ 80, 40 }, 60, 1, BLACK);
	DrawTextEx(font, "Manage Will", Vector2{ 370, 45 }, 50, 1, BLACK);
	DrawTextEx(font, "Exit", Vector2{ 1700, 40 }, 60, 1, BLACK);
	DrawTextEx(font, "Assets", Vector2{ 1115, 220 }, 60, 1, BLACK);
	DrawTextEx(font, "Liabilities", Vector2{ 1510, 220 }, 60, 1, BLACK);
	DrawTextEx(font, "Add New", Vector2{ 1290, 925}, 60, 1, BLACK);
	DrawTextEx(font, "Currently Available", Vector2{ 120, 680 }, 40, 5, DARKGRAY);
	DrawTextEx(font, "Add Cash", { 380,775 }, 50, 5, BLACK);
	DrawRectangleRounded({ 1020, 380, 755,120 }, 0.2, 0, WHITE);
	DrawRectangleRoundedLines({ 1020, 380, 755,130 }, 0.2, 0, 3, BLACK);
	DrawRectangleRounded({ 1020, 530, 755,120 }, 0.2, 0, WHITE);
	DrawRectangleRoundedLines({ 1020, 530, 755,130 }, 0.2, 0, 3, BLACK);
	DrawRectangleRounded({ 1020, 680, 755,120 }, 0.2, 0, WHITE);
	DrawRectangleRoundedLines({ 1020, 680, 755,130 }, 0.2, 0, 3, BLACK);
	DrawTriangle({ 1400, 320 }, { 1360,370 }, { 1440,370 }, DARKBLUE);
	DrawTexture(triangle, 1360, 820, RAYWHITE);
	DrawTextEx(font, currentShown[assetCounter].c_str(), { 1025, 415 }, 60, 0, BLACK);
	DrawTextEx(font, currentShown[assetCounter + 1].c_str(), { 1025, 565 }, 60, 0, BLACK);
	DrawTextEx(font, currentShown[assetCounter + 2].c_str(), { 1025, 715 }, 60, 0, BLACK);
	DrawLineBezier(Vector2{ 1000, 300 }, Vector2{ 1800, 300 }, 5, BLACK); // split line top
	DrawLineBezier(Vector2{ 1000,900 }, Vector2{ 1800,900 }, 5, BLACK); // split line bottom
	DrawLineBezier(Vector2{ 100,500 }, Vector2{ 900,500 }, 5, BLACK);
	DrawLineBezier(Vector2{ 0,120 }, Vector2{ 1920,120 }, 7, BLACK);
	EndDrawing();
}

void addAsset()
{
	string temp;
	cout << "Enter New Asset: " << endl;
	getline(std::cin, temp);
    assets.push_back(temp);
	currentShown.push_back(temp);	
}