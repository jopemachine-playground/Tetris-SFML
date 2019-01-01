#include "pch.h"

#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <CRTDBG.H>
#include <iostream>

#include "Text.h"
#include "GamePool.h"
#include "Ranking.h"
#include "Sound.h"

Ranking* Ranking::mInstance = nullptr;

// 게임 종료 후, 자동으로 호출해 기록된 점수를 읽어옴.
// 기록한 점수가 csv 파일에 기록된 점수의 최저보다 높을 경우 WriteRanking() 호출.
void Ranking::LoadRankingData()
{
	Sound* sc = Sound::GetInstance();

	std::ifstream fin;

	fin.open("Ranking.csv", std::ios_base::in);

	int recordIndex = 0;

	fin.ignore(LLONG_MAX, '\n');
	
	while (fin.is_open() && recordIndex < SAVED_RECORD_NUMBER)
	{

		std::cout << "reading index : " << recordIndex << std::endl;

		// 점수를 읽음
		fin >> mRecord[recordIndex].RecordedScore;
		fin.ignore(LLONG_MAX, ',');

		// 점수를 취득한 날짜
		fin >> mRecord[recordIndex].RecordedDate;
		fin.ignore(LLONG_MAX, '\n');

		if (fin.fail())
		{
			std::cerr << "Error - 'Ranking.csv' reading" << std::endl;
		}

		std::cout << mRecord[recordIndex].RecordedScore << std::endl;
		std::cout << mRecord[recordIndex].RecordedDate << std::endl;

		recordIndex++;

	}

	if (mPlayerScore > mRecord[SAVED_RECORD_NUMBER - 1].RecordedScore)
	{
		if (mPlayerScore > mRecord[0].RecordedScore)
		{
			std::cout << "최고기록 경신!" << std::endl;
		}

		WriteRanking();
	}

	fin.close();

}

// 게임 종료 후, 자동으로 호출해 점수를 기록, 기록 후 LoadRangingData 호출해 화면에 점수 띄움
void Ranking::WriteRanking()
{
	std::string currentDateTime = getCurrentDateTime();

	// Score는 내림차순으로 정렬되어 있어야 함
	for (unsigned int index = 0; index < SAVED_RECORD_NUMBER; index++)
	{
		if (mPlayerScore > mRecord[index].RecordedScore)
		{
			mRecord[index].RecordedScore = mPlayerScore;
			mRecord[index].RecordedDate = currentDateTime;
			break;
		}
	}

	std::ofstream fout;

	fout.open("Ranking.csv", std::ios_base::out | std::ios_base::trunc);

	fout << "score,date\n";

	unsigned int recordIndex = 0;

	while (fout.is_open() && recordIndex < SAVED_RECORD_NUMBER)
	{
		std::cout << "writing index : " << recordIndex << std::endl;

		if (fout.fail())
		{
			std::cerr << "Error - 'Ranking.csv' writing " << std::endl;
			break;
		}
		fout << mRecord[recordIndex].RecordedScore << ',';
		fout << mRecord[recordIndex].RecordedDate << '\n';
		recordIndex++;
	}

	fout.close();
}


// 현재시간을 string type으로 return
const std::string Ranking::getCurrentDateTime() {

	struct tm gmt, localt;
	time_t now_time;
	char buf[256];

	time(&now_time); //현재 초 단위 시간을 측정

	localtime_s(&localt, &now_time);
	asctime_s(buf, sizeof(buf), &localt);

	std::string ret = std::string(buf);
	ret[std::size(ret) - 1] = '\0';

	// 공백을 _로 바꿈 (문자열에 공백이 포함되면 읽을 때 까다로워짐)
	for (unsigned int i = 0; i < size(ret); i++)
	{
		if (ret[i] == ' ')
		{
			ret[i] = '_';
		}
	}
	return ret;
}


void Ranking::AddPlayerScore(int score)
{
	Text* text = Text::GetInstance();
	mPlayerScore += score;
	text->UpdateScore();
}

Ranking::Ranking()
{


}