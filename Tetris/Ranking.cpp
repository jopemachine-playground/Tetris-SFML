#include "pch.h"

#include "Text.h"
#include "GamePool.h"
#include "Ranking.h"

Ranking* Ranking::mInstance = nullptr;

Ranking::Ranking()
{
	
}

// ���� ���� ��, �ڵ����� ȣ���� ��ϵ� ������ �о��.
void Ranking::LoadRankingData() 
{


}

// ���� ���� ��, �ڵ����� ȣ���� ������ ���, ��� �� LoadRangingData ȣ���� ȭ�鿡 ���� ���
void Ranking::WriteRanking()
{


}

void Ranking::AddPlayerScore(int score)
{ 
	Text* text = Text::GetInstance();
	mPlayerScore += score;
	text->UpdateScore();
}