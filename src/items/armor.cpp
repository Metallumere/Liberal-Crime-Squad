#include "../includes.h"

const string CONST_armor011 = "]";
const string CONST_armor010 = "[";
const string tag_D = "D";
const string tag_B = "B";
const string tag_X = "X";
const string tag_quality = "quality";
const string tag_false = "false";
const string tag_damaged = "damaged";
const string tag_true = "true";
const string tag_bloody = "bloody";
const string tag_blood = "blood";
const string tag_armor = "armor";
#include "../items/itemtype.h"
#include "../items/item.h"
#include "../items/armortype.h"
#include "../items/armor.h"
//own header
#include "../common/stringconversion.h"
//for int stringtobool(std::string)
#include "../common/translateid.h"
// for  int getarmortype


Armor::Armor(const std::string& inputXml) : Item(inputXml)
{
	CMarkup xml;
	xml.SetDoc(inputXml);
	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem())
	{
		std::string tag = xml.GetTagName();
		if (tag == tag_bloody) bloody_ = stringtobool(xml.GetData()) == 1;
		else if (tag == tag_damaged) damaged_ = stringtobool(xml.GetData()) == 1;
		else if (tag == tag_quality) quality_ = atoi(xml.GetData().c_str());
	}
}
string Armor::showXml() const
{
	CMarkup xml;
	xml.AddElem(tag_armor);
	xml.IntoElem();
	addBaseValues(xml);
	xml.AddElem(tag_bloody, (bloody_ ? tag_true : tag_false));
	xml.AddElem(tag_damaged, (damaged_ ? tag_true : tag_false));
	xml.AddElem(tag_quality, tostring(quality_));
	return xml.GetDoc();
}
string Armor::equip_title() const
{
	return equip_title(false);
}
string Armor::equip_title(bool full) const
{
	string et = (full ? get_name() : get_shortname());
	if (quality_ <= get_quality_levels() && (bloody_ || damaged_ || quality_ > 1))
	{
		et += CONST_armor010;
		if (quality_ > 9) et += tag_X;
		else if (quality_ > 1) et += tostring(quality_);
		if (bloody_) et += tag_B;
		if (damaged_) et += tag_D;
		et += CONST_armor011;
	}
	return et;
}
Armor* Armor::split(int number)
{
	if (number > number_) number = number_;
	Armor* newi = clone();
	newi->number_ = number;
	number_ -= number;
	return newi;
}
bool Armor::merge(Item& i)
{
	if (i.whatIsThis() == THIS_IS_ARMOR && is_same_type(i))
	{
		Armor& a = static_cast<Armor&>(i); //cast -XML
		if (bloody_ == a.bloody_&&damaged_ == a.damaged_&&quality_ == a.quality_)
		{
			increase_number(a.get_number());
			a.set_number(0);
			return true;
		}
	}
	return false;
}
bool Armor::decrease_quality(int decrease)
{
	quality_ += decrease;
	if (quality_ < 1) quality_ = 1;
	return quality_ <= get_quality_levels();
}
bool Armor::sort_compare_special(Item* other) const
{
	if (other)
	{
		int thisi = getarmortype(get_itemtypename());
		int otheri = getarmortype(other->get_itemtypename());
		if (thisi < otheri || otheri == -1) return false;
		else if (thisi > otheri&&otheri != -1) return true;
		else if (other->whatIsThis() == THIS_IS_ARMOR)
		{
			Armor* a = static_cast<Armor*>(other); //cast... -XML
			if (quality_ < a->quality_) return false;
			else if (quality_ > a->quality_) return true;
			else if (damaged_ != a->damaged_) return damaged_;
			else if (bloody_ != a->bloody_) return bloody_;
			else return false;
		}
		else return false;
	}
	else return false;
}
void Armor::set_damaged(bool d)
{
	if (can_get_damaged() || !d) damaged_ = d;
}
void Armor::set_bloody(bool b)
{
	if (can_get_bloody() || !b) bloody_ = b;
}
const string ruinedName = "Tattered Rags";
const string& Armor::get_name() const
{
	extern vector<ArmorType *> armortype;
	if (quality_ <= get_quality_levels())
		return armortype[getarmortype(get_itemtypename())]->get_name();
	else return ruinedName;
}
const string& Armor::get_shortname() const
{
	extern vector<ArmorType *> armortype;
	if (quality_ <= get_quality_levels())
		return armortype[getarmortype(get_itemtypename())]->get_shortname();
	else return ruinedName;
}
long Armor::get_fencevalue() const
{
	extern vector<ArmorType *> armortype;
	if (quality_ <= get_quality_levels())
		return armortype[getarmortype(get_itemtypename())]->get_fencevalue() / quality_;
	else return 0;
}
int Armor::get_make_difficulty() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->get_make_difficulty();
}
int Armor::get_make_price() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->get_make_price();
}
bool Armor::deathsquad_legality() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->deathsquad_legality();
}
bool Armor::can_get_bloody() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->can_get_bloody();
}
bool Armor::can_get_damaged() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->can_get_damaged();
}
int Armor::get_armor(int bodypart) const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->get_armor(bodypart);
}
bool Armor::has_fireprotection() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->has_fireprotection();
}
bool Armor::covers(int bodypart) const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->covers(bodypart);
}
bool Armor::conceals_face() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->conceals_face();
}
int Armor::get_interrogation_basepower() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->get_interrogation_basepower();
}
int Armor::get_interrogation_assaultbonus() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->get_interrogation_assaultbonus();
}
int Armor::get_interrogation_drugbonus() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->get_interrogation_drugbonus();
}
int Armor::get_professionalism() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->get_professionalism();
}
int Armor::get_stealth_value() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->get_stealth_value();
}
int Armor::get_weaponsize_concealment() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->get_weaponsize_concealment();
}
bool Armor::conceals_weaponsize(int weaponsize) const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->conceals_weaponsize(weaponsize);
}
bool Armor::is_mask() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->is_mask();
}
bool Armor::is_surprise_mask() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->is_surprise_mask();
}
const string Armor::get_description() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->get_description();
}
int Armor::get_durability() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->get_durability();
}
int Armor::get_quality_levels() const
{
	extern vector<ArmorType *> armortype;
	return armortype[getarmortype(get_itemtypename())]->get_quality_levels();
}
extern vector<ArmorType *> armortype;
Armor::Armor(const int seed, int quality, int number)
	: Item(*armortype[seed], number), bloody_(false), damaged_(false), quality_(quality)
{ }

