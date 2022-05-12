#ifndef DATATYPES_H
#define DATATYPES_H



//Tipo de dado coordenada (linha, coluna) para acessar um ponto na matriz//
typedef std::pair<int, int> coord;

//Tipo de dado pessoa (id, level) onde level é o passo que a pessoa foi encontrada//
typedef std::pair<int, int> people;

//Tipo de dado coordAt, para salvar uma coordenada relacionada a um passo//
typedef std::pair<coord, int>coordAt;

#endif // !DATATYPES_H
