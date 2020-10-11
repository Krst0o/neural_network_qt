#include "perceptron.h"
#include <QDebug>

#include <QTime>
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>
#include <QString>


Perceptron::Perceptron(int perceptronNumberSent)
{
    perceptronNumber = perceptronNumberSent;
    GenerateRandomWeights();
    LoadExamples();
}

//Learning function
void Perceptron::Learn()
{

}
//Load examples from file
void Perceptron::LoadExamples()
{
    QString line;
    QFile inputFile("/home/krsto/Dokumenty/qtprojects/NeuralNetwork/Zadanie_1/examples.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
           line = in.readLine();
           //correctAnswer = QString(line).at(0).digitValue();
           trainingInputs.push_back(line);
       }
       inputFile.close();
    }
    for(int i = 0; i < trainingInputs.size(); i++)
        qDebug() << trainingInputs[i];
}
//Generate random weights to learn function
void Perceptron::GenerateRandomWeights()
{
    for(int i = 0; i < 7; i++)
        for(int j = 0; j < 5; j++)
            randomWeights[i][j] = QRandomGenerator::global()->generateDouble();
    randomTeta = QRandomGenerator::global()->generateDouble();
}
