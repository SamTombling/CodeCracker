#ifndef ENCRYPTER_H
#define ENCRYPTER_H

#include <QString>

class Encrypter
{
public:
    Encrypter(const QString &plainText);

    // Public Member Functions
    void substitution();

    // Getters
    QString cypherText() const;

    void setShifts(int newShifts);

private:

    // Member variables
    QString m_plainText;
    QString m_cypherText = "";
    int m_shifts;

    // Private Member Functions
};

#endif // ENCRYPTER_H
