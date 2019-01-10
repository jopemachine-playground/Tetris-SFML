#include "pch.h"

#include <cassert>
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

// ���� ���� ��, �ڵ����� ȣ���� ��ϵ� ������ �о��.
// ����� ������ csv ���Ͽ� ��ϵ� ������ �������� ���� ��� WriteRanking() ȣ��.
void Ranking::LoadRankingData()
{
	Text* txt = Text::GetInstance();
	Sound* sc = Sound::GetInstance();

	std::ifstream fin;

	fin.open("Ranking.csv", std::ios_base::in);

	int recordIndex = 0;

	fin.ignore(LLONG_MAX, '\n');
	
	while (fin.is_open() && recordIndex < SAVED_RECORD_NUMBER)
	{
		// ������ ����
		fin >> mRecord[recordIndex].RecordedScore;
		fin.ignore(LLONG_MAX, ',');

		// ������ ����� ��¥
		fin >> mRecord[recordIndex].RecordedDate;
		fin.ignore(LLONG_MAX, '\n');

		if (fin.fail())
		{
			std::cerr << "Error - fails reading'Ranking.csv'" << std::endl;
			assert(false, "Error - fails reading 'Ranking.csv'");
		}
		recordIndex++;
	}

	if (mPlayerScore > mRecord[SAVED_RECORD_NUMBER - 1].RecordedScore)
	{
		if (mPlayerScore > mRecord[0].RecordedScore)
		{
			txt->SetCongratulationText();
		}
		WriteRanking();
	}

	fin.close();

}

// ���� ���� ��, �ڵ����� ȣ���� ������ ���, ��� �� LoadRangingData ȣ���� ȭ�鿡 ���� ���
void Ranking::WriteRanking()
{
	const char* currentDateTime = getCurrentDateTime();

	// Score�� ������������ ���ĵǾ� �־�� ��
	for (unsigned int index = 0; index < SAVED_RECORD_NUMBER; index++)
	{
		if (mPlayerScore > mRecord[index].RecordedScore)
		{
			Record temp[SAVED_RECORD_NUMBER];
			memcpy(temp, mRecord, sizeof(Record) * SAVED_RECORD_NUMBER);

			for (unsigned int belowIndex = index; belowIndex < SAVED_RECORD_NUMBER - 1; belowIndex++)
			{		
				temp[belowIndex + 1] = mRecord[belowIndex];
			}

			temp[index].RecordedScore = mPlayerScore;
			*temp[index].RecordedDate = *currentDateTime;

			memcpy(mRecord, temp, sizeof(Record) * SAVED_RECORD_NUMBER);

			break;
		}
	}

	std::ofstream fout;

	fout.open("Ranking.csv", std::ios_base::out | std::ios_base::trunc);

	fout << "score,date\n";

	unsigned int recordIndex = 0;

	while (fout.is_open() && recordIndex < SAVED_RECORD_NUMBER)
	{
		if (fout.fail())
		{
			std::cerr << "Error - fails writing 'Ranking.csv'" << std::endl;
			assert(false, "Error - fails writing 'Ranking.csv'");
		}
		fout << mRecord[recordIndex].RecordedScore << ',';
		fout << mRecord[recordIndex].RecordedDate << '\n';
		recordIndex++;
	}

	fout.close();
}

// ����ð��� localtime_s�� ���� return
const char* Ranking::getCurrentDateTime() {

	struct tm localt;
	time_t now_time;
	char time_char[256];

	time(&now_time); //���� �� ���� �ð��� ����

	localtime_s(&localt, &now_time);
	asctime_s(time_char, sizeof(time_char), &localt);

	time_char[std::size(time_char) - 1] = '\0';

	// ������ _�� �ٲ� (���ڿ��� ������ ���ԵǸ� ���� �� ��ٷο���)
	for (unsigned int i = 0; i < std::size(time_char); i++)
	{
		if (time_char[i] == ' ')
		{
			time_char[i] = '_';
		}
	}
	return time_char;
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