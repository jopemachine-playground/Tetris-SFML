#pragma once

// Ranking을 입출력으로 관리

class Ranking
{

private:

	Ranking();

	int mPlayerScore = 0;

	int mRecordedScore[10];

	static Ranking* mInstance;

public:

	static Ranking* GetInstance()
	{
		if (mInstance == 0) {
			mInstance = new Ranking();
		}
		return mInstance;
	}

	// 게임 종료 후, 자동으로 호출해 기록된 점수를 읽어옴.
	void LoadRankingData();

	// 게임 종료 후, 자동으로 호출해 점수를 기록, 기록 후 LoadRangingData 호출해 화면에 점수 띄움
	void WriteRanking();

	void AddPlayerScore(int score);

	int GetPlayerScore() const { return mPlayerScore; }


};
