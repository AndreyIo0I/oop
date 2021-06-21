class CTVSet
{
public:
	CTVSet();
	bool IsTurnedOn() const;
	void TurnOn();
	void TurnOff();
	int GetChannel() const;
	bool SelectChannel(int channel);
private:
	bool m_isOn = false;
	int m_selectedChannel = 1;
};

