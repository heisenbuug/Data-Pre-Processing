class Data {
private:
  std::string path;
  std::vector<string> headers;
  arma::mat data;

public:
  Data(string file_path)
  {
    path = file_path;
    mlpack::data::Load(path, data, true);
    data = data.submat(0, 1, data.n_rows - 1, data.n_cols - 1);
    getHeaders();
  }

  void info()
  {
    cout << typeid(data).name() << endl;
    std::cout << "Index Range: " << data.n_cols << std::endl;
    std::cout << "Data Columns (total " << data.n_rows << "):" << std::endl;
    for (auto i : headers)
      cout << i << endl;
  }
  void getHeaders()
  {
    std::fstream fin;
    fin.open(path, std::ios::in);
    std::string line, word, temp;
    getline(fin, line);
    stringstream s(line);
    while (getline(s, word, ','))
    {
      headers.push_back(word);
    }
  }

  void infoHelper(int lower, int upper)
  {
    for (auto i : headers)
    {
      cout.width(10);
      cout << i << ", ";
    }

    std::cout << std::endl;
    cout.precision(2);
    cout.setf(ios::fixed);
    cout.width(10);
    data.submat(0, upper, data.n_rows - 1, lower).t().raw_print(cout);
  }

  void head()
  {
    infoHelper(4, 0);
  }

  void tail()
  {
    infoHelper(data.n_cols - 1, data.n_cols - 5);
  }
};


int main()
{ 
  Data dataset(../housing.csv");
  dataset.info();
  return 0;
}
