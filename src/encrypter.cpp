#include "encrypter.h"

Encrypter::Encrypter(const QString &plainText)
{
    m_plainText = plainText;
}

QString Encrypter::cypherText() const
{
    return m_cypherText;
}

void Encrypter::substitution(int shifts)
{
    for (QChar letter : m_plainText)
    {
        if (letter.isLetter())
        {
            char16_t shiftedLetter = letter.unicode() + shifts;
            if (shiftedLetter > 0x007A) // Handles 'z'
            {
                shiftedLetter = 0x0061;
            }
            else if (shiftedLetter < 0x0061) // Handles 'a'
            {
                shiftedLetter = 0x007A;
            }
            m_cypherText += shiftedLetter;
        }
        else
        {
            m_cypherText += " ";
        }
    }
}
