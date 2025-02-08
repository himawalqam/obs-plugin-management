#pragma once
#include <QString>

enum class TreeItemClass
{
	Root,
	Installed,
	InstalledSource,
	InstalledOutput,
	InstalledEncoder,
	InstalledService,
	InstalledFilter,
	InstalledTransition,
	Online,
	OnlineSource,
	OnlineOutput,
	OnlineEncoder,
	OnlineService,
	OnlineFilter,
	OnlineTransition,
	About,
};

struct TreeNode {
	TreeItemClass itemClass;
	int level;
	bool lastNode;
	const char* name;

	std::vector<TreeNode> children;
};
