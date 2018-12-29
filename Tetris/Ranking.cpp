#include "pch.h"

#include "GamePool.h"
#include "Ranking.h"

Ranking* Ranking::mInstance = nullptr;

Ranking::Ranking()
{
	
}

// 게임 종료 후, 자동으로 호출해 기록된 점수를 읽어옴.
void Ranking::LoadRankingData() 
{


}

// 게임 종료 후, 자동으로 호출해 점수를 기록, 기록 후 LoadRangingData 호출해 화면에 점수 띄움
void Ranking::WriteRanking()
{


}