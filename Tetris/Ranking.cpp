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

// ���� ���� ��, �ڵ����� ȣ���� ��ϵ� ������ �о��.
// ����� ������ csv ���Ͽ� ��ϵ� ������ �������� ���� ��� WriteRanking() ȣ��.
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

		// ������ ����
		fin >> mRecord[recordIndex].RecordedScore;
		fin.ignore(LLONG_MAX, ',');

		// ������ ����� ��¥
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
			std::cout << "�ְ��� ���!" << std::endl;
		}

		WriteRanking();
	}

	fin.close();

}

// ���� ���� ��, �ڵ����� ȣ���� ������ ���, ��� �� LoadRangingData ȣ���� ȭ�鿡 ���� ���
void Ranking::WriteRanking()
{
	std::string currentDateTime = getCurrentDateTime();

	// Score�� ������������ ���ĵǾ� �־�� ��
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


// ����ð��� string type���� return
const std::string Ranking::getCurrentDateTime() {

	struct tm gmt, localt;
	time_t now_time;
	char buf[256];

	time(&now_time); //���� �� ���� �ð��� ����

	localtime_s(&localt, &now_time);
	asctime_s(buf, sizeof(buf), &localt);

	std::string ret = std::string(buf);
	ret[std::size(ret) - 1] = '\0';

	// ������ _�� �ٲ� (���ڿ��� ������ ���ԵǸ� ���� �� ��ٷο���)
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