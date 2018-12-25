#pragma once

// Ranking�� ��������� ����

class Ranking {

private:

	Ranking();

	int PlayerScore = 0;

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
	void AddPlayerScore() { PlayerScore += 100; }


};
