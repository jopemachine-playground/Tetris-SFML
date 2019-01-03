#pragma once

/* 
Ranking�� ��������� ����
���� ���� ���� 10���� ���ڵ�� ������.
*/
class Ranking
{

private:

	Ranking();

	int mPlayerScore = 0;

	enum { SAVED_RECORD_NUMBER = 10 };

	struct Record
	{
		int RecordedScore = 0;
		char RecordedDate[30] = "empty";
	};

	Record mRecord[SAVED_RECORD_NUMBER];

	static Ranking* mInstance;

	const char* getCurrentDateTime();

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

	inline void ResetPlayerScore() { mPlayerScore = 0; }

	inline int GetPlayerScore() const { return mPlayerScore; }

};
