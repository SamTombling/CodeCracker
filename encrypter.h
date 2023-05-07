#ifndef ENCRYPTER_H
#define ENCRYPTER_H

#include <QString>

class Encrypter
{
public:
    Encrypter(const QString &plainText);

    // Public Member Functions
    void substitution(int shifts);

    // Getters
    QString cypherText() const;

private:

    // Member variables
    QString m_plainText;
    QString m_cypherText = "";

    // Private Member Functions
};

#endif // ENCRYPTER_H
