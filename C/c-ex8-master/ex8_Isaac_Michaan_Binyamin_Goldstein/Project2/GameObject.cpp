#include "GameObject.h"
#include "Square.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::buildMatrix(std::vector<std::vector<std::unique_ptr<GameObject>>>& matrix)
{
	matrix.resize(M + M);
	for (int i = 0; i < matrix.size(); i++)
		matrix[i].resize(N);

	buildPartofMatrix(matrix, 0, 100);
	buildPartofMatrix(matrix, 1, 135);
}

void GameObject::buildPartofMatrix(std::vector<std::vector<std::unique_ptr<GameObject>>>& matrix, int i, int n)
{
	int x, y;
	x = y = n;
	for (int k = 0; k < M; i += 2, k++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = std::make_unique<Square>(x, y);
			x += SIZE + 20;
		}
		y += SIZE + 20;
		x = n;
	}
}