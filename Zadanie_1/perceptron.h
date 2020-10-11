#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include <QVector>

class Perceptron
{
public:
    Perceptron(int perceptronNumberSent);
    double randomWeights[7][5];
    double randomTeta;
    QVector<QString> trainingInputs;
    //double bestWeights[7][5];
    int correctAnswer;
    int perceptronNumber;
    //double learningRate = 0.5;
    //int iteration = 0;
    //double Err = 1;
    //int lifeTime = 0;
    //int record = 0;
    void Learn();
    void LoadExamples();
    void GenerateRandomWeights();

};

#endif // PERCEPTRON_H
