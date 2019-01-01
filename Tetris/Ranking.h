#pragma once

// Ranking�� ��������� ����

class Ranking
{

private:

	Ranking();

	int mPlayerScore = 0;

	struct Record
	{
		int RecordedScore = 0;
		std::string RecordedDate = "empty";
	};

	Record mRecord[10];

	static Ranking* mInstance;

	const std::string getCurrentDateTime();

	const unsigned int SAVED_RECORD_NUMBER = 10;

	// ���� ���� ��, �ڵ����� ȣ���� ������ ���, ��� �� LoadRangingData ȣ���� ȭ�鿡 ���� ���
	void WriteRanking();

public:

	static Ranking* GetInstance()
	{
		if (mInstance == 0) {
			mInstance = new Ranking();
		}
		return mInstance;
	}

	// ���� ���� ��, �ڵ����� ȣ���� ��ϵ� ������ �о��.
	void LoadRankingData();

	void AddPlayerScore(int score);

	void ResetPlayerScore() { mPlayerScore = 0; }

	int GetPlayerScore() const { return mPlayerScore; }


};
