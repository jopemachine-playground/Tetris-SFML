#pragma once

// Ranking�� ��������� ����

class Ranking {

private:

	Ranking();

	int mPlayerScore = 0;

	int mRecordedScore[10];

	static Ranking* mInstance;

public:

	static Ranking* GetInstance() {
		if (mInstance == 0) {
			mInstance = new Ranking();
		}
		return mInstance;
	}

	// ���� ���� ��, �ڵ����� ȣ���� ��ϵ� ������ �о��.
	void LoadRankingData();

	// ���� ���� ��, �ڵ����� ȣ���� ������ ���, ��� �� LoadRangingData ȣ���� ȭ�鿡 ���� ���
	void WriteRanking();

	// ����� �� �� ���� �� ���� 100�� ����
	void AddPlayerScore() { mPlayerScore += 100; }

	int GetPlayerScore() const { return mPlayerScore; }


};
