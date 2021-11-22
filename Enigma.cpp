


Enigma::Enigma {

}


Enigma::createKey {
    std::srand(std::time(nullptr));
    int random = std::rand();
    int keyLength = 26

    for(int i = 0; i < keyLength; i++)
    {
        int x = 1 + std::rand()/((RAND_MAX)/6);
        // _key.push_back(x);
    }
}