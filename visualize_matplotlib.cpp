#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
  // Load data from a text file
  ifstream data_file("grades.csv");
  if (!data_file.is_open()) {
    cout << "Error opening file!" << endl;
    return 1;
  }

  // Store data in vector of maps
  vector<map<string, double>> df_students;
  string header;
  getline(data_file, header);
  while (!data_file.eof()) {
    string line;
    getline(data_file, line);
    if (line.empty()) {
      continue;
    }
    istringstream line_stream(line);
    map<string, double> row;
    string col_name;
    double col_value;
    while (line_stream >> col_name >> col_value) {
      row[col_name] = col_value;
    }
    df_students.push_back(row);
  }

  // Remove any rows with missing data
  df_students.erase(remove_if(df_students.begin(), df_students.end(), [](const auto& row) {
    return any_of(row.begin(), row.end(), [](const auto& col) {
      return isnan(col.second);
    });
  }), df_students.end());

  // Calculate who passed, assuming '60' is the grade needed to pass
  vector<bool> passes(df_students.size());
  transform(df_students.begin(), df_students.end(), passes.begin(), [](const auto& row) {
    return row.at("Grade") >= 60;
  });

  // Print the result out
  for (int i = 0; i < df_students.size(); i++) {
    const auto& row = df_students[i];
    cout << "Name: " << row.at("Name") << " Grade: " << row.at("Grade") << " Pass: " << passes[i] << endl;
  }

  // Calculate statistics
  double min_val = df_students[0].at("Grade");
  double max_val = df_students[0].at("Grade");
  double sum_val = 0;
  vector<double> grades;
  for (const auto& row : df_students) {
    double grade = row.at("Grade");
    min_val = min(min_val, grade);
    max_val = max(max_val, grade);
    sum_val += grade;
    grades.push_back(grade);
  }
  double mean_val = sum_val / df_students.size();
  sort(grades.begin(), grades.end());
  double med_val = grades[grades.size() / 2];
  map<double, int
