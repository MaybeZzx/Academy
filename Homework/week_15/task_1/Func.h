#pragma once
double Action(int* a, int* b, int const& size_A, int const& size_B, double(*func)(int*, int*, int const&, int const&));
double max(int* a, int* b, int const& size_A, int const& size_B);
double min(int* a, int* b, int const& size_A, int const& size_B);
double avg(int* a, int* b, int const& size_A, int const& size_B);