#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}
/*
TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}
*/
TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> mt1(5);
  ASSERT_NO_THROW(TMatrix<int> mt2(mt1));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
  TMatrix<int> mt1(10);
  for (int i=0;i<10;i++)
	  for (int j=i;j<10;j++)
		  mt1[i][j] = i+j;
  TMatrix<int> mt2(mt1);
  EXPECT_EQ(mt1,mt2);
}
/*
TEST(TMatrix, copied_matrix_has_its_own_memory)
{

}
*/
TEST(TMatrix, can_get_size)
{
  TMatrix<int> mt(4);
  EXPECT_EQ(4, mt.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
  TMatrix<int> mt(4);
	mt[1][1] = 10;
	EXPECT_EQ(10, mt[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> mt(4);
	ASSERT_ANY_THROW(mt[-2][3] = 10);
}
/*
TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(4);
	ASSERT_ANY_THROW(m[MAX_MATRIX_SIZE][3] = 10);
}
*/
TEST(TMatrix, can_assign_matrix_to_itself)
{
  const int size = 2;
  TMatrix<int> mt(size);
  for (int i = 0; i < size; i++)
  {
    mt[0][i]=i;
  }
  mt = mt;
  EXPECT_EQ(0, mt[0][0]);
  EXPECT_EQ(1, mt[0][1]);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  const int size = 2;
  TMatrix<int> mt1(size),mt2(size);
  for (int i = 0; i < size; i++)
  {
    mt1[0][i]=i;
  }
  mt2 = mt1;
  EXPECT_EQ(0, mt2[0][0]);
  EXPECT_EQ(1, mt2[0][1]);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
  const int size1 = 2, size2 = 5;
  TMatrix<int> mt1(size1), mt2(size2);
  mt1 = mt2;
  EXPECT_EQ(5, mt1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  const int size1 = 2, size2 = 5;
  TMatrix<int> mt1(size1),mt2(size2);
  for (int i = 0; i < size1; i++)
  {
    mt1[0][i]=i;
  }
  mt2 = mt1;
  EXPECT_EQ(0, mt2[0][0]);
  EXPECT_EQ(1, mt2[0][1]);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  const int size = 2;
  TMatrix<int> mt1(size),mt2(size);
  for (int i = 0; i < size; i++)
  {
    mt1[0][i]=i;
    mt2[0][i]=i;
  }
  EXPECT_EQ(true , mt1==mt2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
const int size = 2;
  TMatrix<int> mt1(size);
  for (int i = 0; i < size; i++)
  {
    mt1[0][i]=i;
  }
  EXPECT_EQ(true , mt1==mt1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  const int size1 = 2, size2 = 5;
  TMatrix<int> mt1(size1),mt2(size2);
  EXPECT_EQ(true, mt1 != mt2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
  const int size = 4;
  TMatrix<int> mt1(size), mt2(size), res(size);
  for (int i = 0;i<size ; i++)
    for (int j = i;j<size ; j++){
		  mt1[i][j] = i;
		  mt2[i][j] = i;
		  res[i][j] = 2*i;
    }
  EXPECT_EQ(res, mt1 + mt2);
}
/*
TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  const int size1 = 4, size2 = 5;
  TMatrix<int> mt1(size1), mt2(size2);
	ASSERT_ANY_THROW(mt1 + mt2);
}
*/
TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
  const int size = 4;
  TMatrix<int> mt1(size), mt2(size), res(size);
  for (int i = 0;i<size ; i++) 
    for (int j = i;j<size ; j++){
		  mt1[i][j] = 3*i;
		  mt2[i][j] = i;
		  res[i][j] = 2*i;  
    }
  EXPECT_EQ(res, mt1 - mt2);
}
/*
TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  const int size1 = 4, size2 = 5;
  TMatrix<int> mt1(size1), mt2(size2);
	ASSERT_ANY_THROW(mt1 - mt2);
}*/