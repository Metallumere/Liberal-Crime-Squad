
#include "../includes.h"
const string CONST_armortypeB044 = ": ";

const string CONST_armortype055 = "UNDEF";
const string CONST_armortype054 = "Unknown element for armor type ";
const string CONST_armortype053 = "::InterrogationST: ";
const string CONST_armortype051 = "::armor: ";
const string CONST_armortype049 = "::body_covering::conceal_face: ";
const string CONST_armortype048 = "Invalid boolean value for armor type ";
const string CONST_armortype047 = "::body_covering::legs: ";
const string CONST_armortype045 = "::body_covering::arms: ";
const string CONST_armortype043 = "::body_covering::head: ";
const string CONST_armortype041 = "::body_covering::body: ";
const string CONST_armortype037 = "::armor::fireprotection: ";
const string CONST_armortype035 = "::deathsquad_legality: ";
const string blankString = "";
const string tag_durability = "durability";
const string tag_qualitylevels = "qualitylevels";
const string tag_quality = "quality";
const string tag_description = "description";
const string tag_surprise = "surprise";
const string tag_mask = "mask";
const string tag_stealth = "stealth";
const string tag_stealth_value = "stealth_value";
const string tag_conceal_weapon_size = "conceal_weapon_size";
const string tag_professionalism = "professionalism";
const string tag_drugbonus = "drugbonus";
const string tag_assaultbonus = "assaultbonus";
const string tag_basepower = "basepower";
const string tag_base = "base";
const string tag_interrogation = "interrogation";
const string tag_shortname = "shortname";
const string tag_conceals_face = "conceals_face";
const string tag_legs = "legs";
const string tag_arms = "arms";
const string tag_head = "head";
const string tag_body = "body";
const string tag_body_covering = "body_covering";
const string tag_fire = "fire";
const string tag_fireprotection = "fireprotection";
const string tag_limbs = "limbs";
const string tag_armor = "armor";
const string tag_can_get_damaged = "can_get_damaged";
const string tag_can_get_bloody = "can_get_bloody";
const string tag_deathsquad_legality = "deathsquad_legality";
const string tag_make_price = "make_price";
const string tag_make_difficulty = "make_difficulty";
#include "../creature/creatureEnums.h"
//#include "../items/item.h"
#include "../items/itemtype.h"
//#include "../items/armor.h"
#include "../items/armortype.h"
//own header
#include "../common/stringconversion.h"
//for stringtobool


//// #include "../includes.h"
/*const string CONST_armortypeB044 = ": ";

const string CONST_armortype055 = "UNDEF";
const string CONST_armortype054 = "Unknown element for armor type ";
const string CONST_armortype053 = "::InterrogationST: ";
const string CONST_armortype051 = "::armor: ";
const string CONST_armortype049 = "::body_covering::conceal_face: ";
const string CONST_armortype048 = "Invalid boolean value for armor type ";
const string CONST_armortype047 = "::body_covering::legs: ";
const string CONST_armortype045 = "::body_covering::arms: ";
const string CONST_armortype043 = "::body_covering::head: ";
const string CONST_armortype041 = "::body_covering::body: ";
const string CONST_armortype037 = "::armor::fireprotection: ";
const string CONST_armortype035 = "::deathsquad_legality: ";
const string tag_durability = "durability";
const string tag_qualitylevels = "qualitylevels";
const string tag_description = "description";
const string tag_surprise = "surprise";
const string tag_mask = "mask";
const string tag_stealth = "stealth";
const string tag_stealth_value = "stealth_value";
const string tag_conceal_weapon_size = "conceal_weapon_size";
const string tag_professionalism = "professionalism";
const string tag_drugbonus = "drugbonus";
const string tag_assaultbonus = "assaultbonus";
const string tag_basepower = "basepower";
const string tag_base = "base";
const string tag_interrogation = "interrogation";
const string tag_shortname = "shortname";
const string tag_conceals_face = "conceals_face";
const string tag_legs = "legs";
const string tag_arms = "arms";
const string tag_head = "head";
const string tag_body = "body";
const string tag_body_covering = "body_covering";
const string tag_fire = "fire";
const string tag_fireprotection = "fireprotection";
const string tag_limbs = "limbs";
const string tag_can_get_damaged = "can_get_damaged";
const string tag_can_get_bloody = "can_get_bloody";
const string tag_deathsquad_legality = "deathsquad_legality";
const string tag_make_price = "make_price";
const string tag_make_difficulty = "make_difficulty";
*/
ArmorType::ArmorType(MCD_STR xmlstring)
	: ItemType(xmlstring),
	make_difficulty_(0), make_price_(0), deathsquad_legality_(false),
	can_get_bloody_(true), can_get_damaged_(true),
	stealth_value_(0), armor_body_(0), armor_head_(0), armor_limbs_(0), fireprotection_(false),
	cover_head_(false), cover_body_(true), cover_arms_(true), cover_legs_(true), conceal_face_(false),
	shortname_(CONST_armortype055), shortname_future_(CONST_armortype055), shortname_defined_(false), shortname_future_defined_(false),
	interrogation_basepower_(0), interrogation_assaultbonus_(0), interrogation_drugbonus_(0),
	professionalism_(2), conceal_weaponsize_(5),
	mask_(false), surprise_mask_(false), description_(CONST_armortype055),
	quality_levels_(4), durability_(10)
{
	init(xmlstring);
}
ArmorType::ArmorType(const ArmorType& base, MCD_STR xmlstring)
	: ItemType(base, xmlstring),
	make_difficulty_(base.make_difficulty_), make_price_(base.make_price_), deathsquad_legality_(base.deathsquad_legality_),
	can_get_bloody_(base.can_get_bloody_), can_get_damaged_(base.can_get_damaged_),
	stealth_value_(base.stealth_value_), armor_body_(base.armor_body_), armor_head_(base.armor_head_), armor_limbs_(base.armor_limbs_), fireprotection_(base.fireprotection_),
	cover_head_(base.cover_head_), cover_body_(base.cover_body_), cover_arms_(base.cover_arms_), cover_legs_(base.cover_legs_), conceal_face_(base.conceal_face_),
	shortname_(base.shortname_), shortname_future_(base.shortname_future_), shortname_defined_(base.shortname_defined_), shortname_future_defined_(base.shortname_future_defined_),
	interrogation_basepower_(base.interrogation_basepower_), interrogation_assaultbonus_(base.interrogation_assaultbonus_), interrogation_drugbonus_(base.interrogation_drugbonus_),
	professionalism_(base.professionalism_), conceal_weaponsize_(base.conceal_weaponsize_),
	mask_(base.mask_), surprise_mask_(base.surprise_mask_), description_(base.description_),
	quality_levels_(base.quality_levels_), durability_(base.durability_)
{
	init(xmlstring);
}


map<string, int> armorTypeInitTags = {
	map<string, int>::value_type(tag_make_difficulty, ENUM_tag_make_difficulty),
	map<string, int>::value_type(tag_make_price, ENUM_tag_make_price),
	map<string, int>::value_type(tag_deathsquad_legality, ENUM_tag_deathsquad_legality),
	map<string, int>::value_type(tag_can_get_bloody, ENUM_tag_can_get_bloody),
	map<string, int>::value_type(tag_can_get_damaged, ENUM_tag_can_get_damaged),
	map<string, int>::value_type(tag_armor, ENUM_tag_armor),
	map<string, int>::value_type(tag_body_covering, ENUM_tag_body_covering),
	map<string, int>::value_type(tag_shortname, ENUM_tag_shortname),
	map<string, int>::value_type(tag_interrogation, ENUM_tag_interrogation),
	map<string, int>::value_type(tag_professionalism, ENUM_tag_professionalism),
	map<string, int>::value_type(tag_conceal_weapon_size, ENUM_tag_conceal_weapon_size),
	map<string, int>::value_type(tag_stealth_value, ENUM_tag_stealth_value),
	map<string, int>::value_type(tag_mask, ENUM_tag_mask),
	map<string, int>::value_type(tag_surprise, ENUM_tag_surprise),
	map<string, int>::value_type(tag_description, ENUM_tag_description),
	map<string, int>::value_type(tag_qualitylevels, ENUM_tag_qualitylevels),
	map<string, int>::value_type(tag_durability, ENUM_tag_durability),
};

void ArmorType::init(const MCD_STR& xmlstring)
{
	CMarkup xml;
	xml.SetDoc(xmlstring);
	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem()) //Loop over all the elements inside the armortype element.
	{
		std::string element = xml.GetTagName();
		int b;
		if (armorTypeInitTags.count(element)) {
			switch (armorTypeInitTags[element]) {
			case ENUM_tag_make_difficulty:
				make_difficulty_ = atoi(xml.GetData());
				break;
			case ENUM_tag_make_price:
				make_price_ = atoi(xml.GetData());
				break;
			case ENUM_tag_deathsquad_legality:
				b = stringtobool(xml.GetData());
				if (b == 1)
					deathsquad_legality_ = true;
				else if (b == 0)
					deathsquad_legality_ = false;
				/*else
				errorlog << CONST_armortype048 << idname()
				<< CONST_armortype035 << xml.GetData() << std::endl;*/
				break;
			case ENUM_tag_can_get_bloody:
				b = stringtobool(xml.GetData());
				if (b == 1)
					can_get_bloody_ = true;
				else if (b == 0)
					can_get_bloody_ = false;
				break;
			case ENUM_tag_can_get_damaged:
				b = stringtobool(xml.GetData());
				if (b == 1)
					can_get_damaged_ = true;
				else if (b == 0)
					can_get_damaged_ = false;
				break;
			case ENUM_tag_armor:
				xml.IntoElem();
				while (xml.FindElem())
				{
					element = xml.GetTagName();
					if (element == tag_body)
						armor_body_ = atoi(xml.GetData());
					else if (element == tag_head)
						armor_head_ = atoi(xml.GetData());
					else if (element == tag_limbs)
						armor_limbs_ = atoi(xml.GetData());
					else if (element == tag_fireprotection)
					{
						b = stringtobool(xml.GetData());
						if (b == 1)
							fireprotection_ = true;
						else if (b == 0)
							fireprotection_ = false;
						/*else
						errorlog << CONST_armortype048 << idname()
						<< CONST_armortype037 << xml.GetData() << std::endl;*/
					}
					/*else
					errorlog << CONST_armortype054 << idname()
					<< CONST_armortype051 << element << endl;*/
				}
				xml.OutOfElem();
				break;
			case ENUM_tag_body_covering:
				xml.IntoElem();
				while (xml.FindElem())
				{
					element = xml.GetTagName();
					if (element == tag_body)
					{
						b = stringtobool(xml.GetData());
						if (b == 1)
							cover_body_ = true;
						else if (b == 0)
							cover_body_ = false;
						/*else
						errorlog << CONST_armortype048 << idname()
						<< CONST_armortype041 << xml.GetData() << std::endl;*/
					}
					else if (element == tag_head)
					{
						b = stringtobool(xml.GetData());
						if (b == 1)
							cover_head_ = true;
						else if (b == 0)
							cover_head_ = false;
						/*else
						errorlog << CONST_armortype048 << idname()
						<< CONST_armortype043 << xml.GetData() << std::endl;*/
					}
					else if (element == tag_arms)
					{
						b = stringtobool(xml.GetData());
						if (b == 1)
							cover_arms_ = true;
						else if (b == 0)
							cover_arms_ = false;
						/*else
						errorlog << CONST_armortype048 << idname()
						<< CONST_armortype045 << xml.GetData() << std::endl;*/
					}
					else if (element == tag_legs)
					{
						b = stringtobool(xml.GetData());
						if (b == 1)
							cover_legs_ = true;
						else if (b == 0)
							cover_legs_ = false;
						/*else
						errorlog << CONST_armortype048 << idname()
						<< CONST_armortype047 << xml.GetData() << std::endl;*/
					}
					else if (element == tag_conceals_face)
					{
						b = stringtobool(xml.GetData());
						if (b == 1)
							conceal_face_ = true;
						else if (b == 0)
							conceal_face_ = false;
						/*else
						errorlog << CONST_armortype048 << idname()
						<< CONST_armortype049 << xml.GetData() << std::endl;*/
					}
					/*else
					errorlog << CONST_armortype054 << idname()
					<< CONST_armortype051 << element << endl;*/
				}
				xml.OutOfElem();
				break;
			case ENUM_tag_shortname:
				shortname_ = xml.GetData();
				shortname_defined_ = true;
				if (len(shortname_) > 14)
					shortname_.resize(14);
				break;
			case ENUM_tag_interrogation:
				xml.IntoElem();
				while (xml.FindElem())
				{
					if (element == tag_basepower)
						interrogation_basepower_ = atoi(xml.GetData());
					else if (element == tag_assaultbonus)
						interrogation_assaultbonus_ = atoi(xml.GetData());
					else if (element == tag_drugbonus)
						interrogation_drugbonus_ = atoi(xml.GetData());
					/*else
					errorlog << CONST_armortype054 << idname()
					<< CONST_armortype053 << element << endl;*/
				}
				xml.OutOfElem();
				break;
			case ENUM_tag_professionalism:
				professionalism_ = atoi(xml.GetData());
				break;
			case ENUM_tag_conceal_weapon_size:
				conceal_weaponsize_ = atoi(xml.GetData());
				break;
			case ENUM_tag_stealth_value:
				stealth_value_ = atoi(xml.GetData());
				break;
			case ENUM_tag_mask:
				b = stringtobool(xml.GetData());
				if (b == 1)
					mask_ = true;
				else if (b == 0)
					mask_ = false;
				break;
			case ENUM_tag_surprise:
				b = stringtobool(xml.GetData());
				if (b == 1)
					surprise_mask_ = true;
				else if (b == 0)
					surprise_mask_ = false;
				break;
			case ENUM_tag_description:
				description_ = xml.GetData();
				break;
			case ENUM_tag_qualitylevels:
				quality_levels_ = max(1, atoi(xml.GetData()));
				break;
			case ENUM_tag_durability:
				durability_ = max(0, atoi(xml.GetData()));
				break;
				/*default:
				errorlog << CONST_armortype054 << idname() << CONST_armortypeB044 << element << endl;
				break;
				*/
			}
		}

	}
	if (!shortname_defined_ && len(name_) <= 14)
		shortname_ = name_;
}
int ArmorType::get_armor(int bodypart) const
{
	if (covers(bodypart))
	{
		switch (bodypart)
		{
		case BODYPART_HEAD:
			return armor_head_;
		case BODYPART_BODY:
			return armor_body_;
		case BODYPART_ARM_RIGHT:
		case BODYPART_ARM_LEFT:
			return armor_limbs_;
		case BODYPART_LEG_RIGHT:
		case BODYPART_LEG_LEFT:
			return armor_limbs_;
		}
	}
	return 0;
}
bool ArmorType::covers(int bodypart) const
{
	switch (bodypart)
	{
	case BODYPART_HEAD: return cover_head_;
	case BODYPART_BODY: return cover_body_;
	case BODYPART_ARM_RIGHT:
	case BODYPART_ARM_LEFT: return cover_arms_;
	case BODYPART_LEG_RIGHT:
	case BODYPART_LEG_LEFT: return cover_legs_;
	}
	return false;
}
const string& ArmorType::get_shortname() const
{
	extern int year;
	if (shortname_future_defined_ && year >= 2100)
		return shortname_future_;
	else if (year >= 2100 && name_future_defined_ && len(name_future_) <= 14)
		return name_future_;
	else //if (shortname_defined_)
		return shortname_;
	/*else if (len(name()) <= 14)
	return name();
	else
	return CONST_armortype055;*/
}
bool ArmorType::conceals_weaponsize(int weaponsize) const
{
	return (conceal_weaponsize_ >= weaponsize);
}
